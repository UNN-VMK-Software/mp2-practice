#include "Pol_List.h"
#include "Pol.h"
#include "POl_Mon.h"
#include "Pol_Link.h"
#include <gtest.h>

TEST(TPolinom, Create_Pol)
{
	ASSERT_NO_THROW(TPolinom a(""));
}

TEST(TPolinom, Two_Empty_Pol_Equal)
{
	TPolinom b("");
	TPolinom a("");
	EXPECT_EQ(a, b);
}

TEST(TPolinom, Build_Pol)
{
	ASSERT_NO_THROW(TPolinom a("5x^3"));
}

TEST(TPolinom, Create_Pol_After_Existing)
{
	TPolinom a("5x^3");
	ASSERT_NO_THROW(TPolinom b(a));
}

TEST(TPolinom, Create_Pol_With_EQ_Mon)
{
	TPolinom a("2x^5+3x^5");
	TPolinom b("5x^5");
	ASSERT_NO_THROW(a, b);
}

TEST(TPolinom, Summa_1)
{
	TPolinom a("10x^2");
	TPolinom b("12y^2");
	ASSERT_NO_THROW(a + b);
}

TEST(TPolinom, Summa_2)
{
	TPolinom a("x^3+2y^2-z");
	TPolinom b("y^3-3xy+2xy^3");
	ASSERT_NO_THROW(a + b);
}

TEST(TPolinom, Summa_is_Correct_1)
{
	TPolinom a("5x^2");
	TPolinom b("6x^7");
	TPolinom c("6x^7+5x^2");
	EXPECT_EQ(c, a + b);
}

TEST(TPolinom, Summa_is_Correct_2)
{
	TPolinom a("x+y+z");
	TPolinom b("x-2y+z^2");
	TPolinom c("2x-y+z^2+z");
	EXPECT_EQ(c, a + b);
}

TEST(TPolinom, Substract_1)
{
	TPolinom a("x+1");
	TPolinom b("x-1");
	ASSERT_NO_THROW(a + b);
}
TEST(TPolinom, Substract_2)
{
	TPolinom a("x^2+5");
	TPolinom b("x^2-4");
	ASSERT_NO_THROW(a + b);
}

TEST(TPolinom, Substract_is_Correct_1)
{
	TPolinom a("x+1");
	TPolinom b("x-1");
	TPolinom c("-2");
	EXPECT_EQ(c, b - a);
}

TEST(TPolinom, Substract_is_Correct_2)
{
	TPolinom a("x+2y");
	TPolinom b("x-z");
	TPolinom c("2y+z");
	EXPECT_EQ(c, a - b);
}

TEST(TPolinom, Mult_Two_Pol_1)
{
	TPolinom a("x^3");
	TPolinom b("y^4");
	ASSERT_NO_THROW(a * b);
}
TEST(TPolinom, Mult_Two_Pol_2)
{
	TPolinom a("10x^2");
	TPolinom b("12y^2");
	ASSERT_NO_THROW(a * b);
}

TEST(TPolinom, Mult_Two_Pol_is_Correct_1)
{
	TPolinom a("2x^2");
	TPolinom b("2y^2");
	TPolinom c("4x^2y^2");
	EXPECT_EQ(c, a * b);
}
TEST(TPolinom, Mult_Two_Pol_is_Correct_2)
{
	TPolinom a("x+1");
	TPolinom b("x-1");
	TPolinom c("x^2-1");
	EXPECT_EQ(c, a * b);
}

TEST(TPolinom, ERROR_Mult_St_Over_10_1)
{
	TPolinom a("3x^4");
	TPolinom b("x^8");
	ASSERT_ANY_THROW(a * b);
}
TEST(TPolinom, ERROR_Mult_St_Over_10_2)
{
	TPolinom a("y^2");
	TPolinom b("y^8");
	ASSERT_ANY_THROW(a * b);
}

TEST(TPolinom, Group_Equal_St_1)
{
	TPolinom a("xyz+xy");
	TPolinom b("z+2");
	TPolinom c("xyz^2+xyz+2xyz+2xy");
	TPolinom d("xyz^2+3xyz+2xy");
	EXPECT_EQ(c, a * b);
	EXPECT_EQ(c, d);
}

TEST(TPolinom, Group_Equal_St_2)
{
	TPolinom a("x+yz");
	TPolinom b("2x+yz");
	TPolinom c("2x^2+2xyz+xyz+y^2z^2");
	TPolinom d("2x^2+3xyz+y^2z^2");
	EXPECT_EQ(c, a * b);
	EXPECT_EQ(c, d);
}
TEST(TPolinom, Mult_Pol_On_Double_1)
{
	TPolinom a("x^2");
	double b = 20.9;
	ASSERT_NO_THROW(a * b);
}

TEST(TPolinom, Mult_Pol_On_Double_2)
{
	TPolinom a("x^2+y-z");
	double b = 5.5;
	ASSERT_NO_THROW(a * b);
}

TEST(TPolinom, Mult_Pol_On_Double_is_Correct_1)
{
	TPolinom a("100x^3");
	double b = 19.5;
	TPolinom c("1950x^3");
	EXPECT_EQ(c, a * b);
}
TEST(TPolinom, Mult_Pol_On_Double_is_Correct_2)
{
	TPolinom a("10x^2-2y+4z");
	double b = 3.5;
	TPolinom c("35x^2-7y+14z");
	EXPECT_EQ(c, a * b);
}
TEST(TPolinom, Mult_Pol_On_Double_OtherSide_1)
{
	double b = 20.9;
	TPolinom a("x^2");
	ASSERT_NO_THROW(b * a);
}

TEST(TPolinom, Mult_Pol_On_Double_OtherSide_2)
{
	double b = 5.5;
	TPolinom a("x^2+y-z");
	ASSERT_NO_THROW(b * a);
}

TEST(TPolinom, Mult_Pol_On_Double_OtherSide_is_Correct_1)
{
	double b = 19.5;
	TPolinom a("100x^3");
	TPolinom c("1950x^3");
	EXPECT_EQ(c, b* a);
}
TEST(TPolinom, Mult_Pol_On_Double_OtherSide_is_Correct_2)
{
	double b = 3.5;
	TPolinom a("10x^2-2y+4z");
	TPolinom c("35x^2-7y+14z");
	EXPECT_EQ(c, b * a);
}
TEST(TMonom, can_create_node)
{
	ASSERT_NO_THROW(Monom a);
}

TEST(TRingList, can_create_list)
{
	ASSERT_NO_THROW(TRingList<int> l);
}

class EmptyList : public testing::Test
{
protected:
	TRingList<int> Example;
public:
	EmptyList() {};
	~EmptyList() {};
};

TEST_F(EmptyList, Copy_Empty)
{
	ASSERT_NO_THROW(TRingList<int>variable(Example));
}

TEST_F(EmptyList, Copy_Empty_Correct)
{
	TRingList<int>variable(Example);
	variable.Reset();
	EXPECT_EQ(Example.GetCurrent(), Example.GetNext());
}


TEST_F(EmptyList, Eq_Two_Empty)
{
	TRingList<int> variable;
	EXPECT_EQ(true, Example == variable);
}

TEST_F(EmptyList, Assign_Two_Empty)
{
	TRingList<int> variable;
	ASSERT_NO_THROW(Example = variable);
}

TEST_F(EmptyList, Assign_Two_Emptyi_Correct1)
{
	TRingList<int> variable;
	Example = variable;
	EXPECT_EQ(Example.GetCurrent(), Example.GetNext());
}


TEST_F(EmptyList, Insert_To_Tail_For_Empty)
{
	Example.InsertInEnd(5);
	Example.Reset();
	EXPECT_EQ(5, Example.GetCurrent()->data);
	EXPECT_EQ(Example.GetCurrent(), Example.GetCurrent()->pNext->pNext);
}


TEST_F(EmptyList, Search_For_Empty)
{
	ASSERT_NO_THROW(Example.Search(5));
}

TEST_F(EmptyList, Search_For_Empty_Correct)
{
	TLink<int>* p = Example.Search(6);
	EXPECT_EQ(NULL, p);
}

TEST_F(EmptyList, Clean_Empty)
{
	ASSERT_NO_THROW(Example.Clean());
}

TEST_F(EmptyList, Can_Not_Del_From_Empty)
{
	ASSERT_ANY_THROW(Example.Delete(5));
}

TEST_F(EmptyList, Del_From_Empty_Correct)
{
	Example.InsertInEnd(5);
	Example.Delete(5);
	Example.Reset();
	EXPECT_EQ(Example.GetCurrent(), Example.GetCurrent()->pNext);
}

TEST_F(EmptyList, Can_Not_Del_Not_Memb)
{
	Example.InsertInEnd(5);
	ASSERT_ANY_THROW(Example.Delete(6));
}

TEST_F(EmptyList, Clean_Empty_Correct)
{
	Example.Clean();
	Example.Reset();
	EXPECT_EQ(Example.GetCurrent(), Example.GetCurrent()->pNext);
}

class ThreeNodesList : public testing::Test
{
protected:
	TRingList<int> Example;
public:
	ThreeNodesList()
	{
		Example.InsertInEnd(1);
		Example.InsertInEnd(2);
		Example.InsertInEnd(3);
	}
	~ThreeNodesList() {};
};

TEST_F(ThreeNodesList, 3_Nodes_Correct)
{
	Example.Reset();
	EXPECT_EQ(1, Example.GetCurrent()->data);
	EXPECT_EQ(2, Example.GetCurrent()->pNext->data);
	EXPECT_EQ(3, Example.GetCurrent()->pNext->pNext->data);
	EXPECT_EQ(Example.GetCurrent()->pNext->pNext->pNext, Example.GetCurrent()->pNext->pNext->pNext->pNext->pNext->pNext->pNext);
}

TEST_F(ThreeNodesList, Copy_Not_Empty)
{
	ASSERT_NO_THROW(TRingList<int> variable(Example));
}

TEST_F(ThreeNodesList, Copy_Of_Not_Empty_Correct)
{
	TRingList<int> variable(Example);
	variable.Reset();
	EXPECT_EQ(1, variable.GetCurrent()->data);
	EXPECT_EQ(2, variable.GetCurrent()->pNext->data);
	EXPECT_EQ(3, variable.GetCurrent()->pNext->pNext->data);
	EXPECT_EQ(variable.GetCurrent()->pNext->pNext->pNext, variable.GetCurrent()->pNext->pNext->pNext->pNext->pNext->pNext->pNext);
}

TEST_F(ThreeNodesList, Insert_In_End_For_Not_Empty)
{
	Example.InsertInEnd(5);
	Example.Reset();
	EXPECT_EQ(5, Example.GetCurrent()->pNext->pNext->pNext->data);
	EXPECT_EQ(Example.GetCurrent()->pNext->pNext->pNext->pNext, Example.GetCurrent()->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext);
}

TEST_F(ThreeNodesList, Search_For_Not_Empty)
{
	ASSERT_NO_THROW(Example.Search(3));
}

TEST_F(ThreeNodesList, sSearch_For_Not_Empty_Correct)
{
	Example.Reset();
	TLink<int> * p = Example.Search(3);
	TLink<int> * ptrue = Example.GetCurrent()->pNext->pNext;
	EXPECT_EQ(ptrue, p);
}

TEST_F(ThreeNodesList, Search_Not_a_Member_For_Not_Empty)
{
	ASSERT_NO_THROW(Example.Search(5));
}

TEST_F(ThreeNodesList, Search_Not_a_Member_for_Not_Empty_Correct)
{
	TLink<int> * p = Example.Search(7);
	EXPECT_EQ(nullptr, p);
}

TEST_F(ThreeNodesList, can_clean_not_empty_list)
{
	ASSERT_NO_THROW(Example.Clean());
}

TEST_F(ThreeNodesList, Clean_Not_Empty_Correct)
{
	Example.Clean();
	Example.Reset();
	EXPECT_EQ(Example.GetCurrent(), Example.GetCurrent()->pNext);
}


TEST_F(ThreeNodesList, Assign_2_Not_Empty)
{
	TRingList<int> variable;
	variable.InsertInEnd(22);
	variable.InsertInEnd(33);
	ASSERT_NO_THROW(Example = variable);
}

TEST_F(ThreeNodesList, Assign_2_Not_Empty_Of_EQ_SIZE)
{
	TRingList<int> variable;
	variable.InsertInEnd(11);
	variable.InsertInEnd(22);
	variable.InsertInEnd(33);
	Example = variable;
	Example.Reset();
	EXPECT_EQ(11, Example.GetCurrent()->data);
	EXPECT_EQ(22, Example.GetCurrent()->pNext->data);
	EXPECT_EQ(33, Example.GetCurrent()->pNext->pNext->data);
	EXPECT_EQ(Example.GetCurrent()->pNext->pNext->pNext, Example.GetCurrent()->pNext->pNext->pNext->pNext->pNext->pNext->pNext);
}

TEST_F(ThreeNodesList, Compare_2_EQ_Correct)
{
	TRingList<int> variable(Example);
	EXPECT_EQ(true, Example == variable);
}


class TwoListsTest : public testing::Test
{
protected:
	TRingList<int> Example;
	TRingList<int> variable;
	TRingList<int> z;

public:
	TwoListsTest()
	{
		Example.InsertInEnd(1);
		Example.InsertInEnd(2);
		Example.InsertInEnd(3);
		variable.InsertInEnd(11);
		variable.InsertInEnd(22);
	}

	~TwoListsTest() {}
};

TEST_F(TwoListsTest, Assign_2_Not_Empty_Of_Not_EQ_SIZE)
{
	ASSERT_NO_THROW(Example = variable);
}

TEST_F(TwoListsTest, Assign_2_Not_Empty_Of_Not_EQ_SIZE_Correct)
{
	Example = variable;
	Example.Reset();
	EXPECT_EQ(11, Example.GetCurrent()->data);
	EXPECT_EQ(22, Example.GetCurrent()->pNext->data);
	EXPECT_EQ(Example.GetCurrent()->pNext->pNext, Example.GetCurrent()->pNext->pNext->pNext->pNext->pNext);
}

TEST_F(TwoListsTest, Assign_To_Empty_Correct)
{
	Example = z;
	Example.Reset();
	EXPECT_EQ(Example.GetCurrent()->pNext, Example.GetCurrent());
}

TEST_F(TwoListsTest, Assign_Empty_To_Not_Empty_Correct)
{
	z = Example;
	EXPECT_EQ(Example, z);
}

TEST_F(TwoListsTest, Compare_2_Not_Empty)
{
	ASSERT_NO_THROW(Example == variable);
}

TEST_F(TwoListsTest, Compare_2_Not_EQ_of_EQ_SIZE)
{
	variable.Insert(3);
	EXPECT_EQ(false, Example == variable);
}

TEST_F(TwoListsTest, Compare_2_Not_EQ_With_Bigger_Left)
{
	EXPECT_EQ(false, Example == variable);
}

TEST_F(TwoListsTest, Compare_2_Not_EQ_With_Bigger_Right)
{
	EXPECT_EQ(false, variable == Example);
}

TEST_F(TwoListsTest, Compare_With_Empty_Left)
{
	EXPECT_EQ(false, z == variable);
}

TEST_F(TwoListsTest, Compare_With_Empty_Right)
{
	int s;
	EXPECT_EQ(false, variable == z);
}