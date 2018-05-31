#include "gtest.h"
#include "Polinom.h"
#include <vector>

using namespace std;


TEST(Polinom, degree_not_more_than_9_1)
{
	Polinom a("x^4"), b("x^5");
	ASSERT_NO_THROW(a*b);
}

TEST(Polinom, degree_not_more_than_9_2)
{
	Polinom a("z^5"), b("z^9");
	ASSERT_ANY_THROW(a*b);
}


struct Calc
{
	string a, b, res;
	double c;
	Calc(string s, string ia, string ib = "", double ic = 0)
	{
		a = ia;
		b = ib;
		c = ic;
		res = s;
	}
};



class Summa : public ::testing::TestWithParam<Calc>
{
protected:
	Polinom pa, pb, pres;
public:
	Summa() : pa(GetParam().a), pb(GetParam().b), pres(GetParam().res) {}
	~Summa() {}
};

TEST_P(Summa, sum_of_polynoms)
{
	EXPECT_EQ(pres, pa + pb);
}

INSTANTIATE_TEST_CASE_P(Inst2, Summa, ::testing::Values(
	Calc("", "0.9", "-0.9"),
	Calc("", "-6y-2", "6y+2"),
	Calc("", "2.1zy", "-2.1zy"),
	Calc("2x", "2x", ""),
	Calc("x+z", "x", "z"),
	Calc("7x", "10x", "-3x"),
	Calc("8zy^3+2x", "5zy^3", "3zy^3+2x"),
	Calc("2xy+z+1", "9+xy+5z", "xy-8-4z"),
	Calc("0.5x+z", "8.5x+y", "-8x-y+z")
));



class Mult : public ::testing::TestWithParam<Calc>
{
protected:
	Polinom pa, pb, pres;
public:
	Mult() : pa(GetParam().a), pb(GetParam().b), pres(GetParam().res) {}
	~Mult() {}
};

TEST_P(Mult, polynom_mult_polynom)
{
	EXPECT_EQ(pres, pa * pb);
}

INSTANTIATE_TEST_CASE_P(Inst3, Mult, ::testing::Values(
	Calc("48", "2", "24"),
	Calc("x", "x", "1"),
	Calc("xz", "x", "z"),
	Calc("15x^3", "5x^2", "3x"),
	Calc("34.02xz", "8.1x", "4.2z"),
	Calc("25x^2z^5", "-5x", "-5xz^5"),
	Calc("-2z^2-9z+4yz+20y+5", "1+4y-2z", "z+5"),
	Calc("xz^2+2xyz+xy^2z", "xz", "z+2y+y^2"),
	Calc("10+5z+2xz+xz^2", "xz+5", "z+2")
));



class Mult_const : public ::testing::TestWithParam<Calc>
{
protected:
	Polinom p, pres;
	double cn;
public:
	Mult_const() : p(GetParam().a), pres(GetParam().res) { cn = GetParam().c; }
	~Mult_const() {}
};

TEST_P(Mult_const, polynom_mult_const)
{
	EXPECT_EQ(pres, p * cn);
}

INSTANTIATE_TEST_CASE_P(Inst4, Mult_const, ::testing::Values(
	Calc("", "z", "", 0),
	Calc("-8x", "x", "", -8),
	Calc("12x-18", "-6x+9", "", -2),
	Calc("16xy+104x-8", "8xy+52x-4", "", 2),
	Calc("4.5yz+18x+1.5y", "3yz+12x+y", "", 1.5)
));