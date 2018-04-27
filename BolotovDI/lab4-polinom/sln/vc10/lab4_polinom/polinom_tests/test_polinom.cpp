#include "gtest.h"
#include "TPolinom.h"

TEST(TMonom, can_create_monom)
{
	ASSERT_NO_THROW(TMonom M);
}

TEST(TPolinom, can_create_polinom)
{
	ASSERT_NO_THROW(TPolinom p);
}

TEST(TPolinom, can_copy_polinoms)
{
	TPolinom a("x^5");
	ASSERT_NO_THROW(TPolinom b(a));
}

TEST(TPolinom, can_assign_polinoms)
{
	TPolinom a("x^5");
	TPolinom b;
	ASSERT_NO_THROW(b=a);
}

TEST(TPolinom, can_sum_polinoms)
{
	TPolinom a("x^5");
	TPolinom b("x^5");
	TPolinom c("2x^5");
	EXPECT_EQ(c, a+b);
}

TEST(TPolinom, can_dif_polinoms)
{
	TPolinom a("x^5+y^7-500");
	TPolinom b("x^5-y^7-500");
	TPolinom c("2y^7");
	EXPECT_EQ(c, a - b);
}

TEST(TPolinom, can_mul_polinoms)
{
	TPolinom a("x^5+y^7-500");
	TPolinom b("2+z^2");
	TPolinom c("2x^5+2y^7-1000+x^5*z^2+y^7*z^2-500z^2");
	EXPECT_EQ(c, a * b);
}

TEST(TPolinom, can_mul_polinom)
{
	TPolinom a("x^5+y^7-500");
	int k = 10;
	TPolinom c("10x^5+10y^7-5000");
	EXPECT_EQ(c, a*k);
}

TEST(TPolinom, can_mul_polinomsss)
{
	TPolinom a("xyz+x^2*y^2");
	TPolinom c("xyz-y^2");
	TPolinom b("x^2*y^2*z^2-x*y^3*z+x^3*y^3*z-x^2*y^4");
	EXPECT_EQ(b, a*c);
}