#include <gtest.h>
#include "polinom.h"
#include "monom.h"
// тесты мономов и полиномов
//
//struct Monom_mod
//{
//	string s;
//	bool isCorrect;
//	Monom From_string;
//	Monom Real;
//
//	Monom_mod(string s, Monom Real2) :From_string(s)
//	{
//		this->s = s;
//		//this->Real.Push(Real2);
//		if (From_string == Real) isCorrect = true; else isCorrect = false;
//	}
//};
//
//class ParameterizedMonom : public ::testing::TestWithParam<Monom_mod>
//{
//
//};
//
//
//Monom_mod myarray[] = { Monom_mod("3x2",Monom(3,200)), Monom_mod("15y2",Monom(15,20)), Monom_mod("z8",Monom(1,8)), Monom_mod("-1y5x1z8",Monom(-1,158)) };
//
//INSTANTIATE_TEST_CASE_P(Instantiation1,
//	ParameterizedMonom,
//	::testing::ValuesIn(myarray));
//
//TEST_P(ParameterizedMonom, can_create_monom_from_string)
//{
//		EXPECT_EQ(GetParam().isCorrect, true);
//}
//
//struct Polinom_mod_pl
//{
//	string s;
//	bool isCorrect_plus;
//	Polinom A;
//	Polinom B;
//	Polinom res;
//
//	Polinom_mod_pl (string s, Polinom A, Polinom B) : res(s)
//	{
//		this->s = s;
//		this->A = A;
//		this->B = B;
//		Polinom res2 = A + B;
//		if  (res2 == res) isCorrect_plus = true; else isCorrect_plus = false;
//	}
//};
//
//class ParameterizedPolinom_plus : public ::testing::TestWithParam<Polinom_mod_pl>
//{
//};
//
//
//Polinom_mod_pl myarray3[] = { Polinom_mod_pl("x8",Polinom("2x8"), Polinom("-x8")),Polinom_mod_pl("x8+y2-1",Polinom("2x8+5y2+3"), Polinom("-x8-4-4y2")) };
//
//INSTANTIATE_TEST_CASE_P(Instantiation2,
//	ParameterizedPolinom_plus,
//	::testing::ValuesIn(myarray3));
//
//TEST_P(ParameterizedPolinom_plus,can_right_plus_polinoms)
//{
//	EXPECT_EQ(GetParam().isCorrect_plus, true);
//}
//
//
//struct Polinom_mod_mul
//{
//	string s;
//	bool isCorrect_mul;
//	Polinom A;
//	Polinom B;
//	Polinom res;
//
//	Polinom_mod_mul(string s, Polinom A, Polinom B) : res(s)
//	{
//		this->s = s;
//		this->A = A;
//		this->B = B;
//		Polinom res2 = A * B;
//		if (res2 == res) isCorrect_mul = true; else isCorrect_mul = false;
//	}
//};
//
//class ParameterizedPolinom_multyply : public ::testing::TestWithParam<Polinom_mod_mul>
//{
//};
//
//
//Polinom_mod_mul myarray4[] = { Polinom_mod_mul("x8",Polinom("2x2"), Polinom("0.5x6")), Polinom_mod_mul("z2",Polinom("8z1"), Polinom("0.125z1")) };
//
//INSTANTIATE_TEST_CASE_P(Instantiation2,
//	ParameterizedPolinom_multyply,
//	::testing::ValuesIn(myarray4));
//
//TEST_P(ParameterizedPolinom_multyply, can_right_multyply_polinoms)
//{
//	EXPECT_EQ(GetParam().isCorrect_mul, true);
//}
