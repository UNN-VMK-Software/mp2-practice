#include <gtest.h>
#include "polinom.h"
#include <vector>

using std::vector;

TEST(Polinom, can_create_polinom)
{
	ASSERT_NO_THROW(Polinom p);
}

TEST(Polinom, can_create_polinom_str)
{
	string s = "abc";
	Ringlist<Monom> b;
	b.InsertToOrdered(Monom(1, 111));
	Polinom c(b);
	Polinom a(s);
	ASSERT_NO_THROW(Polinom a(s));
	EXPECT_EQ(a, c);
}

TEST(Polinom, can_create_polinom_str1)
{
	string s = "abc+abc";
	Ringlist<Monom> b;
	b.InsertToOrdered(Monom(2, 111));
	//b.InsertToOrdered(Monom(-1, 20));
	Polinom c(b);
	Polinom a(s);
	EXPECT_EQ(a, c);
}

TEST(Polinom, can_create_polinom_str2)
{
	string s1 = "10a^2b^2+c^2";
	string s2 = "8a^2b^2-c^2";
	Polinom c("18a^2b^2");
	Polinom a1(s1), a2(s2);
	Polinom a = a1 + a2;
	EXPECT_EQ(a, c);
}

TEST(Polinom, can_copy_polinoms)
{
	Polinom b("abc");
	ASSERT_NO_THROW(Polinom a(b));
	//EXPECT_EQ(Polinom a(b), Polinom c(Monom(1, 111)));
}

class PolTestParse
{
public:

	string s;
	Polinom res;

	PolTestParse(string str, vector<Monom> &M)
	{
		s = str;
		Ringlist<Monom> temp;
		for (int i = 0; i < M.size(); i++)
			temp.InsertToOrdered(M[i]);
		res = Polinom(temp);
	}
};

class TestParsing : public ::testing::TestWithParam< PolTestParse>
{
protected:
	Polinom P1;
public:
	TestParsing() : P1(GetParam().s) {}
	~TestParsing() {}
};

TEST_P(TestParsing, test_polinom_parsing)
{
	EXPECT_EQ(GetParam().res, P1);
}

INSTANTIATE_TEST_CASE_P(FIRST, TestParsing, ::testing::Values(
	PolTestParse("0", vector<Monom> {Monom()}),
	PolTestParse("abc", vector<Monom> {Monom(1, 111)}),
	PolTestParse("cba", vector<Monom> {Monom(1, 111)}),
	PolTestParse("bac", vector<Monom> {Monom(1, 111)}),
	PolTestParse("a", vector<Monom> {Monom(1, 100)}),
	PolTestParse("b", vector<Monom> {Monom(1, 10)}),
	PolTestParse("c", vector<Monom> {Monom(1, 1)}),
	PolTestParse("a^2", vector<Monom> {Monom(1, 200)}),
	PolTestParse("b^2", vector<Monom> {Monom(1, 20)}),
	PolTestParse("c^2", vector<Monom> {Monom(1, 2)}),
	PolTestParse("a^2bc", vector<Monom> {Monom(1, 211)}),
	PolTestParse("a+b", vector<Monom> {Monom(1, 100), Monom(1, 10)}),
	PolTestParse("a-b", vector<Monom> {Monom(1, 100), Monom(-1, 10)}),
	PolTestParse("a^2-b^2", vector<Monom> {Monom(1, 200), Monom(-1, 20)}),
	PolTestParse("abc+abc", vector<Monom> {Monom(2, 111)}),
	PolTestParse("a^2b^2c^2", vector<Monom> {Monom(1, 222)})
));


class TGeneralPol
{
public:
	string P1, P2, res;
	TGeneralPol(string RES, string POL1, string POL2)
	{
		P1 = POL1;
		P2 = POL2;
		res = RES;
	}
};
//............................................................................

class TestSum : public ::testing::TestWithParam<TGeneralPol>
{
public:
	Polinom pol1, pol2, Res;
	TestSum() : pol1(GetParam().P1), pol2(GetParam().P2), Res(GetParam().res) {};
	~TestSum() {};
};
//............................................................................

TEST_P(TestSum, sum)
{
	EXPECT_EQ(Res, pol1 + pol2);
}
//............................................................................

INSTANTIATE_TEST_CASE_P(SECOND, TestSum, ::testing::Values(
	TGeneralPol("0", "1", "-1"),
	TGeneralPol("0", "a", "-a"),
	TGeneralPol("0", "-abc", "abc"),
	TGeneralPol("2abc", "bca", "abc"),
	TGeneralPol("a+b", "a", "b"),
	TGeneralPol("3.14a", "3a", "0.14a"),
	TGeneralPol("18a^2b^2", "10a^2b^2+c^2", "8a^2b^2-c^2")
));
//............................................................................


//class TestMult : public ::testing::TestWithParam<TGeneralPol>
//{
//public:
//	Polinom pol1, pol2, Res;
//
//	TestMult() : pol1(GetParam().P1), pol2(GetParam().P2), Res(GetParam().res) {}
//	~TestMult() {}
//};
//
//TEST_P(TestMult, mult)
//{
//	EXPECT_EQ(Res, pol1 * pol2);
//}
//
//INSTANTIATE_TEST_CASE_P(THIRD, TestMult, ::testing::Values(
//	TGeneralPol("2", "2", "1"),
//	TGeneralPol("abc", "abc", "1"),
//	TGeneralPol("abc^2", "ac", "cb"),
//	TGeneralPol("100a^2", "50a", "2a"),
//	TGeneralPol("111abc", "55.5ab", "2c"),
//	TGeneralPol("a+b+c", "1", "a+b+c"),
//	TGeneralPol("a^2-b^2", "a-b", "a+b"),
//	TGeneralPol("a^3+b^3", "a+b", "a^2-ab+c^2"),
//	TGeneralPol("a^3-b^3", "a-b", "a^2+ab+c^2")
//));