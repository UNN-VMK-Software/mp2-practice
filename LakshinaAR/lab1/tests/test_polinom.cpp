#include "gtest.h"
#include "polinom.h"
#include <vector>

using namespace std;


TEST(polynom, degree_not_more_than_9_1 )    
{
	polynom a("x^4"), b("x^5");
	ASSERT_NO_THROW(a*b);
}
   
TEST(polynom, degree_not_more_than_9_2 )    
{
	polynom a("x^5"), b("x^5");
	ASSERT_ANY_THROW(a*b);
}


struct calc_st
{
	string a,b,res;
	double c;
	calc_st(string s, string ia, string ib = "", double ic = 0)
	{
		a = ia;
		b = ib;
		c = ic;
		res = s;
	}
};


// Сумма полиномов
class sum_cl : public ::testing::TestWithParam<calc_st>
{
protected:
	polynom pa, pb, pres;
public:
	sum_cl() : pa(GetParam().a),  pb(GetParam().b),   pres(GetParam().res) {}
	~sum_cl() {}
};

TEST_P(sum_cl, sum_of_polynoms)
{
	EXPECT_EQ(pres, pa+pb);
}

INSTANTIATE_TEST_CASE_P(Inst2, sum_cl,::testing::Values(             
		calc_st("", "0.9", "-0.9"),
		calc_st("", "-6y-2", "6y+2"), 
		calc_st("", "2.1zy", "-2.1zy"),
		calc_st("2x","2x", ""),
		calc_st("x+z","x","z"),
		calc_st("7x", "10x", "-3x"),
		calc_st("8zy^3+2x", "5zy^3", "3zy^3+2x"),
		calc_st("2xy+z+1", "9+xy+5z", "xy-8-4z"),
		calc_st("0.5x+z", "8.5x+y", "-8x-y+z")
	));


// Умножение полинома на полином
class mult_pol_cl : public ::testing::TestWithParam<calc_st>
{
protected:
	polynom pl, pr, pres;
public:
	mult_pol_cl() : pl(GetParam().a),  pr(GetParam().b),  pres(GetParam().res) {} 
	~mult_pol_cl() {}
};

TEST_P(mult_pol_cl, polynom_mult_polynom)
{
	EXPECT_EQ(pres, pl * pr);
}

INSTANTIATE_TEST_CASE_P(Inst3, mult_pol_cl,::testing::Values(  
		calc_st("48","2", "24"),
		calc_st("x","x", "1"),
		calc_st("xz","x", "z"),
		calc_st("15x^3", "5x^2", "3x"),
		calc_st("34.02xz", "8.1x", "4.2z"), 
		calc_st("25x^2z^5", "-5x", "-5xz^5"),
		calc_st("-2z^2-9z+4yz+20y+5", "1+4y-2z", "z+5"),          
		calc_st("xz^2+2xyz+xy^2z","xz", "z+2y+y^2"),
		calc_st("10+5z+2xz+xz^2","xz+5", "z+2")  
	));


// Умножение полинома на константу
class mult_const_cl : public ::testing::TestWithParam<calc_st>
{
protected: 
	polynom p, pres;
	double cn;
public:
	mult_const_cl() : p(GetParam().a),   pres(GetParam().res) { cn = GetParam().c; }
	~mult_const_cl() {}
};

TEST_P(mult_const_cl, polynom_mult_const)
{
	EXPECT_EQ(pres, p * cn);
}

INSTANTIATE_TEST_CASE_P(Inst4, mult_const_cl,::testing::Values(
	calc_st("", "x", "", 0),
	calc_st("-4z", "z", "", -4),
	calc_st("12x-18", "-6x+9", "", -2),
	calc_st("16xy+104x-8", "8xy+52x-4", "", 2),	
	calc_st("4.5yz+18x+1.5y", "3yz+12x+y", "", 1.5)		
	));
