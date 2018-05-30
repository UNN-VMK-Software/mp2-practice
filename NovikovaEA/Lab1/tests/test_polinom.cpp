#include "polinom.h"
#include <gtest.h>

TEST(monom, create)
{
	monom a;
	EXPECT_EQ(a.abc, 0);
	EXPECT_EQ(a.coeff, 0.0);
}

TEST(monom, create_copy)
{
	monom a(10.0), b(a);
	EXPECT_EQ(b.coeff, 10.0);
	EXPECT_EQ(b.abc, 0);
}

TEST(monom, create_monom)
{
	string a = "10x2y5z";
	monom b(a);
	EXPECT_EQ(b.coeff, 10.0);
	EXPECT_EQ(b.abc, 251);
}

TEST(monom, equate)
{
	monom a(10.0, 1), b(5.0);
	a = b;
	EXPECT_EQ(a.coeff, 5.0);
	EXPECT_EQ(a.abc, 0);
}

TEST(monom, equall)
{
	monom a(10.0, 1), b(5.0);
	EXPECT_NE(a == b, true);
}

TEST(monom, not_equall)
{
	monom a(10.0, 1), b(5.0);
	EXPECT_NE(a, b);
}

TEST (monom, comparsion)
{
	monom a(10.0, 1), b(5.0);
	EXPECT_EQ(a > b, true); 
}

TEST(monom, mult_const)
{
	monom a(3.0, 3);
	monom c;
	double d = 5.0;
	c = a*d;
	EXPECT_EQ(c.coeff, 15.0);
}

TEST(monom, multiplication)
{
	monom a(3.0, 10), b(4.0, 5), c;
	c = a*b;
	EXPECT_EQ(c.coeff, 12.0);
	EXPECT_EQ(c.abc, 15);
}

TEST(polinom, create)
{
	ASSERT_NO_THROW(polinom a);
}

TEST(polinom, createe)
{
	string s = "xyz+5";
	ASSERT_NO_THROW(polinom a(s));
}

TEST(polinom, copy)
{
	polinom a("2xy+5");
	ASSERT_NO_THROW(polinom b(a));
}

TEST(polinom, copyy)
{
	polinom a("2xy+5");
	polinom b(a);
	EXPECT_EQ(b, a);
}

TEST(polinom, can_assign)
{
	polinom a("2xy+10z");
	polinom b("5+xy-z");
	b = a;
	EXPECT_EQ(b, a);
}

TEST(polinom, not_equal)
{
	polinom a("2xy+10z");
	polinom b("5+xy-z");
	EXPECT_EQ(a != b, true);
}

TEST(polinom, equal)
{
	polinom a("2xy+10z");
	polinom b("2xy+10z");
	EXPECT_EQ(a == b, true);
}


TEST(polinom, addition)
{
	polinom a("2xy+10z");
	polinom b("xy-10z");
	polinom c("3xy");
	EXPECT_EQ(c, a + b);
}

TEST(polinom, multconst)
{
	polinom a("2xy+10z");
	double d = 5.0;
	polinom c("10xy+50z");
	EXPECT_EQ(c, a*d);
}

TEST(polinom, multiplicate)
{
	polinom a("2xy+10z");
	polinom b("5z");
	polinom c("10xyz+50z2");
	EXPECT_EQ(c, a*b);
}









