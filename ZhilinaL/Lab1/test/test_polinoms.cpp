/*#include "gtest.h"
#include "Polinom.h"
#include <vector>

using namespace std;
struct calc_st
{
	string a, b, res;
	double c;
	calc_st(string s, string ia, string ib = "", double ic = 0)
	{
		a = ia;
		b = ib;
		c = ic;
		res = s;
	}
};
class Test_Polinom : public testing::Test
{
protected:
	Polinom p1;
	Polinom p2;
	string s1;
	string s2 = "x^5";
public:
	//Test_Polinom() { l2.Insert(2), l2.Insert(5); }
	~Test_Polinom() {};
};
TEST_F(Test_Polinom, can_create_polinom)
{
	ASSERT_NO_THROW(Polinom p);
}
TEST_F(Test_Polinom, can_create_polinom_from_string)
{
	ASSERT_NO_THROW(Polinom p(s2));
}
TEST_F(Test_Polinom, can_assign_polinom_to_string)
{
	ASSERT_NO_THROW(Polinom p=s1);
}

TEST(Test_Polinom, can_copy_polinom)
{
	ASSERT_NO_THROW(Polinom a("x^5"));
}*/