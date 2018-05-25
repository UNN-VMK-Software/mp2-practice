#include "RingList.h"
#include "Polinoms.h"
#include <gtest.h>

//class Polinom : public testing::Test
//{
//protected:
//	TPolinom p;
//	std::string s;
//public:
//	TPolinom ("") {};
//	//~TPolinpom() {};
//};
//
//TEST(TPolinom, can_create_polinom)
//{
//	ASSERT_NO_THROW(TPolinom a(""));
//}
//
//TEST(TPolinom, two_empty_polinoms_are_equal)
//{
//	TPolinom b("");
//	TPolinom a("");
//	EXPECT_EQ(a, b);
//}
//
//TEST(TPolinom, can_build_polinom)
//{
//	ASSERT_NO_THROW(TPolinom a("10x^2"));
//}
//
//TEST(TPolinom, can_create_polinom_after_existing)
//{
//	TPolinom a("10x^2");
//	ASSERT_NO_THROW(TPolinom b(a));
//}
//
//TEST(TPolinom, can_sum_two_polinoms)
//{
//	TPolinom a("10x^2");
//	TPolinom b("12y^2");
//	ASSERT_NO_THROW(a + b);
//}
//
//TEST(TPolinom, sum_of_two_polinoms_is_correct)
//{
//	TPolinom a("10x^2");
//	TPolinom b("12y^2");
//	TPolinom c("10x^2+12y^2");
//	EXPECT_EQ(c, a + b);
//}
//
//TEST(TPolinom, can_multiple_two_polinoms)
//{
//	TPolinom a("10x^2");
//	TPolinom b("12y^2");
//	ASSERT_NO_THROW(a * b);
//}
//
//TEST(TPolinom, multiple_of_two_polinoms_is_correct)
//{
//	TPolinom a("10x^2");
//	TPolinom b("12y^2");
//	TPolinom c("120x^2y^2");
//	EXPECT_EQ(c, a * b);
//}
//
//TEST(TPolinom, can_multiple_polinom_on_double)
//{
//	TPolinom a("10x^2");
//	double b = 21.5;
//	ASSERT_NO_THROW(a * b);
//}
//
//TEST(TPolinom, multiple_polinom_on_double_is_correct)
//{
//	TPolinom a("10x^2");
//	double b = 21.5;
//	TPolinom c("215x^2");
//	EXPECT_EQ(c, a * b);
//}