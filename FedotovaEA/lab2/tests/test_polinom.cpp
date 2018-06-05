#include "polinom.h"
#include <gtest.h>

TEST(TMonom, can_create)
{
	TMonom a;
	EXPECT_EQ(a.abc, 0);
	EXPECT_EQ(a.coeff, 0.0);
}

TEST(TMonom, can_create_copied)
{
	TMonom a(2.0), b(a);
	EXPECT_EQ(b.coeff, 2.0);
	EXPECT_EQ(b.abc, 0);
}

TEST(TMonom, can_create2)
{
	string a = "3x2y3z";
	TMonom b(a);
	EXPECT_EQ(b.coeff, 3.0);
	EXPECT_EQ(b.abc, 231);
}

TEST(TMonom, can_assign)
{
	TMonom a(2.0, 3), b(1.0);
	a = b;
	EXPECT_EQ(a.coeff, 1.0);
	EXPECT_EQ(a.abc, 0);
}

TEST(TMonom, can_compare_equall)
{
	TMonom a(2.0, 3), b(1.0);
	EXPECT_NE(a == b, true);
}

TEST(TMonom, can_compare_not_equall)
{
	TMonom a(2.0, 3), b(1.0);
	EXPECT_NE(a, b);
}

TEST(TMonom, can_compare1)
{
	TMonom a(2.0, 3), b(1.0);
	EXPECT_EQ(a > b, true); //
}

TEST(TMonom, can_mult_const1)
{
	TMonom a(2.0, 3);
	TMonom c;
	double d = 5.0;
	c = a * d;
	EXPECT_EQ(c.coeff, 10.0);
}

TEST(TMonom, can_mult_const2)
{
	TMonom a(2.0, 3);
	TMonom c;
	double d = 5.0;
	c = d * a;
	EXPECT_EQ(c.coeff, 10.0);
}

TEST(TMonom, can_mult)
{
	TMonom a(2.0, 3), b(3.0, 21), c;
	c = a * b;
	EXPECT_EQ(c.coeff, 6.0);
	EXPECT_EQ(c.abc, 24);
}

TEST(TMonom, can_check)
{
	TMonom a(2.0, 800), b(3.0, 200), c;
	ASSERT_ANY_THROW(TMonom c = a * b);
}


TEST(TPolinom, can_create)
{
	ASSERT_NO_THROW(TPolinom a);
}

TEST(TPolinom, can_create2)
{
	string s = "xy-1";
	ASSERT_NO_THROW(TPolinom a(s));
}

TEST(TPolinom, can_create_copied)
{
	TPolinom a("x+1");
	ASSERT_NO_THROW(TPolinom b(a));
}

TEST(TPolinom, can_create_copied2)
{
	TPolinom a("x+1");
	TPolinom b(a);
	EXPECT_EQ(b, a);
}

TEST(TPolinom, can_assign)
{
	TPolinom a("xy+z");
	TPolinom b("1+x");
	b = a;
	EXPECT_EQ(b, a);
}

TEST(TPolinom, can_compare_not_equal)
{
	TPolinom a("xy+z");
	TPolinom b("1+x");
	EXPECT_EQ(a != b, true);
}

TEST(TPolinom, can_compare_equal)
{
	TPolinom a("xy+z");
	TPolinom b("xy+z");
	EXPECT_EQ(a == b, true);
}


TEST(TPolinom, can_addition1)
{
	TPolinom a("-xy+z");
	TPolinom b("xy+z");
	TPolinom c("2z");
	EXPECT_EQ(c, a + b);
}

TEST(TPolinom, can_addition2)
{
	TPolinom a("2x2+3xyz+1");
	TPolinom b("2+x2+z");
	TPolinom c("3+z+3xyz+3x2");
	EXPECT_EQ(c, a + b);
}

TEST(TPolinom, can_mult1)
{
	TPolinom a("-xy+z");
	TPolinom b("xy+z");
	TPolinom c("z2-x2y2");
	EXPECT_EQ(c, a*b);
}

TEST(TPolinom, can_mult2)
{
	TPolinom a("-xy+z+1");
	TPolinom b("xy+z");
	TPolinom c("z+xy+z2-x2y2");
	EXPECT_EQ(c, a*b);
}

TEST(TPolinom, can_mult_const1)
{
	TPolinom a("-xy+z+1");
	double d = 0.0;
	TPolinom c;
	EXPECT_EQ(c, a*d);
}

TEST(TPolinom, can_mult_const2)
{
	TPolinom a("-xy+z+1");
	double d = 2.0;
	TPolinom c("-2xy+2z+2");
	EXPECT_EQ(c, a*d);
}

TEST(TPolinom, can_mult_const3)
{
	TPolinom a("-xy+z+1");
	double d = 2.0;
	TPolinom c("-2xy+2z+2");
	EXPECT_EQ(c, d*a);
}

//ïîäîáíûå â ïîëèíîìå

TEST(TPolinom, can_pod1)
{
	TPolinom a("-xy+2-1+4xy+z");
	TPolinom b("x+1");
	TPolinom c1("2+x+z+3xy");
	EXPECT_EQ(c1, a + b);
}

TEST(TPolinom, can_pod2)
{
	TPolinom a("-xy+2-1+4xy+z");
	TPolinom b("x+1+2x-3");
	TPolinom c1("-1+3x+z+3xy");
	EXPECT_EQ(c1, a + b);
}

TEST(TPolinom, can_pod3)
{
	TPolinom a("-xy+2-1+4xy");
	TPolinom b("x");
	TPolinom c1("x+3x2y");
	EXPECT_EQ(c1, a * b);
}

TEST(TPolinom, can_pod4)
{
	TPolinom a("-x+x");
	TPolinom b("x");
	TPolinom c1;
	EXPECT_EQ(c1, a*b);
}