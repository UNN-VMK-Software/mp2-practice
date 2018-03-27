#include "gtest.h"
#include "polynom.h"

struct tparse
{
	string expr;
	polynom res;
	tparse(string str, const vector<monom> &v)
	{
		expr = str;
		list<monom> temp;
		for (int i = 0; i < v.size(); i++)
			temp.InsertOrd(v[i]);
		res = polynom(temp);
	}
};

class pol_parse : public ::testing::TestWithParam<tparse>
{
protected: polynom pol;
public:
	pol_parse() : pol(GetParam().expr)	{}
	~pol_parse() {}
};

TEST_P(pol_parse, parse_of_polynom)
{
	EXPECT_EQ(GetParam().res, pol);
}

INSTANTIATE_TEST_CASE_P(1,
	pol_parse,
	::testing::Values(
		tparse("", vector<monom> {}),		
		tparse("0.75", vector<monom> {monom(0.75, 0)}),
		tparse("-3.4", vector<monom> {monom(-3.4, 0)}),
		tparse("xyz", vector<monom> {monom(1, 111)}),
		tparse("5.76xzy", vector<monom> {monom(5.76, 111)}),
		tparse("-yxz", vector<monom> {monom(-1, 111)}),			
		tparse("z+6y^8+9x", vector<monom> {monom(9, 100), monom(6, 80), monom(1, 1)}),
		tparse("-3.89zy+35.0x^3y-2z^4x-8", vector<monom> {monom(35,310), monom(-2,104), monom(-3.89,11), monom(-8,0)}),
		tparse("2+2x^2y^2-2xz^5", vector<monom> {monom(2,220), monom(-2,105), monom(2, 0)})
	
	));

INSTANTIATE_TEST_CASE_P(2,
	pol_parse,
	::testing::Values(
		tparse("x+x+4x+x+3", vector<monom> {monom(7, 100), monom (3,0)}),
		tparse("xy-yx", vector<monom> {}),
		tparse("0.46z+z", vector<monom> {monom(1.46, 1)}),
		tparse("1+3", vector<monom> {monom(4, 0)}),
		tparse("x^2+x+1+3x^2-2x+1+1", vector<monom> {monom(4, 200), monom(-1,100), monom(3)}),
		tparse("xy^2+z+x-2z+9x+3", vector<monom> {monom(1, 120), monom(10, 100), monom(-1, 1), monom(3, 0)})
	));


struct tcalc
{
	string l,r,res;	
	double c;
	
	tcalc(string ires, string il, string ir, double ic = 0)
	{
		l = il;
		r = ir;
		c = ic;
		res = ires;
	}
};

class pol_plus : public ::testing::TestWithParam<tcalc>
{
protected: polynom pl, pr, pres;
public:
	pol_plus() : pl(GetParam().l), pr(GetParam().r), pres(GetParam().res)	{}
	~pol_plus() {}
};

TEST_P(pol_plus, polynom_plus_polynom)
{
	EXPECT_EQ(pres, pl + pr);
}

INSTANTIATE_TEST_CASE_P(3,
	pol_plus,
	::testing::Values(
		tcalc("4", "1", "3"),
		tcalc("x+y+z", "x+y", "z"),
		tcalc("", "xy", "-xy"),
		tcalc("x^7", "x^7", ""),
		tcalc("x^8y^3z+5+yz^7", "x^8y^3z+8-xy+yz^7", "-3+xy"),
		tcalc("9.67yz^5", "yz^5", "8.67z^5y"),
		tcalc("5x^2+y+x+6", "y+4x^2+2", "x^2+x+4"),
		tcalc("", "0", "-0"),
		tcalc("", "x+y", "-x-y"),
		tcalc("-3", "", "-3z^0")
	));

TEST(polynom, power_is_more_than_9_while_mult)
{
	polynom a("x"), b("x^9");
	ASSERT_ANY_THROW(a*b);
}

class pol_mult : public ::testing::TestWithParam<tcalc>
{
protected: polynom pl, pr, pres;
public:
	pol_mult() : pl(GetParam().l), pr(GetParam().r), pres(GetParam().res) {}
	~pol_mult() {}
};

TEST_P(pol_mult, polynom_mult_polynom)
{
	EXPECT_EQ(pres, pl * pr);
}

INSTANTIATE_TEST_CASE_P(4,
	pol_mult,
	::testing::Values(
		tcalc("15", "3", "5"),
		tcalc("x^8", "x", "x^7"),
		tcalc("-20x^2y^2-4x^2y", "-4yx", "5xy+x"),
		tcalc("x^2-1", "x+1", "x-1"),
		tcalc("", "xyz", ""),
		tcalc("", "0xyz", "7"),
		tcalc("", "x", "0"),
		tcalc("x^2-16", "-x+4", "-x-4"),
		tcalc("-0.45xyz^9", "-0.45x", "yz^9"),
		tcalc("x^3+x^2y+x^2z-x^2", "x+y+z-1", "x^2")		
	));

class c_mult : public ::testing::TestWithParam<tcalc>
{
protected: polynom p, pres; double k;
public:
	c_mult() : p(GetParam().l), pres(GetParam().res)
	{
		k = GetParam().c;
	}
	~c_mult() {}
};

TEST_P(c_mult, polynom_mult_const)
{
	EXPECT_EQ(pres, p * k);
}

INSTANTIATE_TEST_CASE_P(5,
	c_mult,
	::testing::Values(
		tcalc("", "x", "", 0),
		tcalc("xy^2", "xy^2", "", 1),
		tcalc("-5.4x-5.4y^8z", "x+y^8z", "", -5.4),
		tcalc("21z", "-3z", "", -7),
		tcalc("y^3", "0.5y^3", "", 2)
	));