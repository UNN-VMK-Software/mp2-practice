#include "polinom.h"
#include <gtest.h>

TEST(Polinom, can_create_polinom)
{
	string s = "2abc";
	ASSERT_NO_THROW(Polinom a(s));
}

//TEST(polynom, degree_not_more_than_9_1)
//{
//	Polinom a("4"), b("x^5");
//	ASSERT_NO_THROW(a*b);
//}