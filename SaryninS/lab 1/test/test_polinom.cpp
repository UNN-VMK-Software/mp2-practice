#include "gtest.h"
#include "polinom.h"
#include <vector>

using std::vector;

TEST(Monom, can_create_monom)
{
	ASSERT_NO_THROW(Monom M);
}

TEST(Polinom, can_create_polinom)
{
	ASSERT_NO_THROW(Polinom p);
}

TEST(Polinom, can_copy_polinoms)
{
	Polinom B("x^2y^3z");
	ASSERT_NO_THROW(Polinom A(B));
}

struct string_test
{
	string s;
	Polinom res;
	string_test(string str, const vector<Monom> &vec)
	{
		s = str;
		List<Monom> tmp;
		for (int i = 0; i < vec.size(); i++)
			tmp.InsertOrdered(vec[i]);
		res = Polinom(tmp);
	}
};

class testpars : public ::testing::TestWithParam<string_test>
{
protected: 
	Polinom P;
public:
	testpars() : P(GetParam().s){}
	~testpars() {}
};

TEST_P(testpars, correct_parse_of_polynom_strings)
{
	EXPECT_EQ(GetParam().res, P);
}

INSTANTIATE_TEST_CASE_P(tst1,testpars,::testing::Values(
		string_test("0", vector<Monom> {Monom()}),
		string_test("-zyx", vector<Monom> {Monom(-1, 111)}),
		string_test("-2x^2", vector<Monom> {Monom(-2, 200)}),
		string_test("z^2", vector<Monom> {Monom(1, 2)}),
		string_test("x^2yz", vector<Monom> {Monom(1, 211)}),
		string_test("x+y", vector<Monom> {Monom(1, 100), Monom(1, 10)}),
		string_test("17.9xy", vector<Monom> {Monom(17.9, 110)})
	));

class Operat
{
public:
	string P1, P2, res;

	Operat(string r, string a, string b)
	{
		P1 = a;
		P2 = b;
		res = r;
	}
};


class TestSum : public ::testing::TestWithParam<Operat>
{
public:
	Polinom pol1, pol2, Res;

	TestSum() : pol1(GetParam().P1), pol2(GetParam().P2), Res(GetParam().res) {};
	~TestSum() {};
};


TEST_P(TestSum, sum)
{
	EXPECT_EQ(Res, pol1 + pol2);
}


INSTANTIATE_TEST_CASE_P(tst2, TestSum, ::testing::Values(
	Operat("0", "1", "-1"),
	Operat("0", "x", "-x"),
	Operat("0", "-xyz", "xyz"),
	Operat("2xyz", "yzx", "xyz"),
	Operat("x+y", "x", "y"),
	Operat("3.14x", "3x", "0.14x"),
	Operat("18x^2y^2", "10x^2y^2+x^2", "8x^2y^2-x^2")
));


class TestMult : public ::testing::TestWithParam<Operat>
{
public:
	Polinom pol1, pol2, Res;

	TestMult() : pol1(GetParam().P1), pol2(GetParam().P2), Res(GetParam().res) {}
	~TestMult() {}
};

TEST_P(TestMult, mult)
{
	EXPECT_EQ(Res, pol1 * pol2);
}

INSTANTIATE_TEST_CASE_P(tst3, TestMult, ::testing::Values(
	Operat("2", "2", "1"),
	Operat("xyz", "xyz", "1"),
	Operat("xyz^2", "xz", "yz"),
	Operat("200x^3", "10x", "20x^2"),
	Operat("12xyz", "6xy", "2z"),
	Operat("x+y+z", "1", "x+y+z"),
	Operat("x^2-y^2", "x-y", "x+y"),
	Operat("x^3+y^3", "x+y", "y^2-xy+x^2")
));