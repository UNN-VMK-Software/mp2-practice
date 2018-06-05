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

TEST(TPolinom, can_create_polinom_with_equal_monoms)
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

TEST_F(EmptyList, can_assign_two_empty_lists)
{
	TRingList<int> variable;
	ASSERT_NO_THROW(Example = variable);
}

TEST_F(EmptyList, assign_two_empty_lists_is_correct)
{
	TRingList<int> variable;
	Example = variable;
	EXPECT_EQ(Example.GetCurrent(), Example.GetNext());
}


TEST_F(EmptyList, can_insert_to_tail_for_empty_list)
{
	Example.InsertInEnd(5);
	Example.Reset();
	EXPECT_EQ(5, Example.GetCurrent()->data);
	EXPECT_EQ(Example.GetCurrent(), Example.GetCurrent()->pNext->pNext);
}


TEST_F(EmptyList, can_search_for_empty_list)
{
	ASSERT_NO_THROW(Example.Search(5));
}

TEST_F(EmptyList, search_for_empty_list_is_correct)
{
	TLink<int>* p = Example.Search(6);
	EXPECT_EQ(NULL, p);
}

TEST_F(EmptyList, can_clean_empty_list)
{
	ASSERT_NO_THROW(Example.Clean());
}

TEST_F(EmptyList, can_not_delete_from_empty_list)
{
	ASSERT_ANY_THROW(Example.Delete(5));
}

TEST_F(EmptyList, delete_from_empty_list_is_correct)
{
	Example.InsertInEnd(5);
	Example.Delete(5);
	Example.Reset();
	EXPECT_EQ(Example.GetCurrent(), Example.GetCurrent()->pNext);
}

TEST_F(EmptyList, ca_not_delete_not_a_member_of_list)
{
	Example.InsertInEnd(5);
	ASSERT_ANY_THROW(Example.Delete(6));
}

TEST_F(EmptyList, clean_empty_list_is_correct)
{
	Example.Clean();
	Example.Reset();
	EXPECT_EQ(Example.GetCurrent(), Example.GetCurrent()->pNext);
}




//------------------------------------------------------------------------------------------

class ThreeNodesList : public testing::Test
{
protected:
	TRingList<int> l;
public:
	ThreeNodesList()
	{
		l.InsertInEnd(1);
		l.InsertInEnd(2);
		l.InsertInEnd(3);
	}
	~ThreeNodesList() {};
};

TEST_F(ThreeNodesList, three_nodes_list_is_correct)
{
	l.Reset();
	EXPECT_EQ(1, l.GetCurrent()->data);
	EXPECT_EQ(2, l.GetCurrent()->pNext->data);
	EXPECT_EQ(3, l.GetCurrent()->pNext->pNext->data);
	EXPECT_EQ(l.GetCurrent()->pNext->pNext->pNext, l.GetCurrent()->pNext->pNext->pNext->pNext->pNext->pNext->pNext);
}


TEST_F(ThreeNodesList, can_copy_not_empty_list)
{
	ASSERT_NO_THROW(TRingList<int> l2(l));
}

TEST_F(ThreeNodesList, copy_of_not_empty_list_is_correct)
{
	TRingList<int> l2(l);
	l2.Reset();
	// òàê íàïèñàíî, ò.ê. ïðåäïîëàãàåì, ÷òî == åùå íå ðåàëèçîâàíî èëè íå ðàáîòàåò
	EXPECT_EQ(1, l2.GetCurrent()->data);
	EXPECT_EQ(2, l2.GetCurrent()->pNext->data);
	EXPECT_EQ(3, l2.GetCurrent()->pNext->pNext->data);
	EXPECT_EQ(l2.GetCurrent()->pNext->pNext->pNext, l2.GetCurrent()->pNext->pNext->pNext->pNext->pNext->pNext->pNext);
}




TEST_F(ThreeNodesList, can_insert_in_end_for_not_empty_list)
{
	l.InsertInEnd(5);
	l.Reset();
	EXPECT_EQ(5, l.GetCurrent()->pNext->pNext->pNext->data);
	EXPECT_EQ(l.GetCurrent()->pNext->pNext->pNext->pNext, l.GetCurrent()->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext);
}




TEST_F(ThreeNodesList, can_search_for_not_empty_list)
{
	ASSERT_NO_THROW(l.Search(3));
}

TEST_F(ThreeNodesList, search_for_not_empty_list_is_correct)
{
	l.Reset();
	TLink<int> * p = l.Search(3);
	TLink<int> * ptrue = l.GetCurrent()->pNext->pNext;
	EXPECT_EQ(ptrue, p);
}

TEST_F(ThreeNodesList, can_search_not_a_member_for_not_empty_list)
{
	ASSERT_NO_THROW(l.Search(5));
}

TEST_F(ThreeNodesList, search_not_a_member_for_not_empty_list_is_correct)
{
	TLink<int> * p = l.Search(7);
	EXPECT_EQ(nullptr, p);
}

TEST_F(ThreeNodesList, can_clean_not_empty_list)
{
	ASSERT_NO_THROW(l.Clean());
}

TEST_F(ThreeNodesList, clean_not_empty_list_is_correct)
{
	l.Clean();
	l.Reset();
	EXPECT_EQ(l.GetCurrent(), l.GetCurrent()->pNext);
}


TEST_F(ThreeNodesList, can_assign_two_not_empty_lists)
{
	TRingList<int> l2;
	l2.InsertInEnd(22);
	l2.InsertInEnd(33);
	ASSERT_NO_THROW(l = l2);
}

TEST_F(ThreeNodesList, can_assign_two_not_empty_lists_of_eq_size)
{
	TRingList<int> l2;
	l2.InsertInEnd(11);
	l2.InsertInEnd(22);
	l2.InsertInEnd(33);
	l = l2;
	l.Reset();
	EXPECT_EQ(11, l.GetCurrent()->data);
	EXPECT_EQ(22, l.GetCurrent()->pNext->data);
	EXPECT_EQ(33, l.GetCurrent()->pNext->pNext->data);
	EXPECT_EQ(l.GetCurrent()->pNext->pNext->pNext, l.GetCurrent()->pNext->pNext->pNext->pNext->pNext->pNext->pNext);
}

TEST_F(ThreeNodesList, compare_two_eq_lists_is_correct)
{
	TRingList<int> l2(l);
	EXPECT_EQ(true, l == l2);
}


class TwoListsTest : public testing::Test
{
protected:
	TRingList<int> l;
	TRingList<int> l2;
	TRingList<int> z;

public:
	TwoListsTest()
	{
		l.InsertInEnd(1);
		l.InsertInEnd(2);
		l.InsertInEnd(3);
		l2.InsertInEnd(11);
		l2.InsertInEnd(22);
	}

	~TwoListsTest() {}
};

TEST_F(TwoListsTest, can_assign_two_not_empty_lists_of_not_eq_size)
{
	ASSERT_NO_THROW(l = l2);
}

TEST_F(TwoListsTest, assign_two_not_empty_lists_of_not_eq_size_is_correct)
{
	l = l2;
	l.Reset();
	EXPECT_EQ(11, l.GetCurrent()->data);
	EXPECT_EQ(22, l.GetCurrent()->pNext->data);
	EXPECT_EQ(l.GetCurrent()->pNext->pNext, l.GetCurrent()->pNext->pNext->pNext->pNext->pNext);
}

TEST_F(TwoListsTest, assign_list_to_empty_is_correct)
{
	l = z;
	l.Reset();
	EXPECT_EQ(l.GetCurrent()->pNext, l.GetCurrent());
}

TEST_F(TwoListsTest, assign_empty_list_to_not_empty_is_correct)
{
	z = l;
	EXPECT_EQ(l, z);
}

TEST_F(TwoListsTest, can_compare_two_not_empty_lists)
{
	ASSERT_NO_THROW(l == l2);
}

TEST_F(TwoListsTest, compare_two_not_eq_lists_of_eq_size)
{
	l2.Insert(3);
	EXPECT_EQ(false, l == l2);
}

TEST_F(TwoListsTest, compare_two_not_eq_lists_with_bigger_list_left)
{
	EXPECT_EQ(false, l == l2);
}

TEST_F(TwoListsTest, compare_two_not_eq_lists_with_bigger_list_right)
{
	EXPECT_EQ(false, l2 == l);
}

TEST_F(TwoListsTest, compare_list_with_empty_list_left)
{
	EXPECT_EQ(false, z == l2);
}

TEST_F(TwoListsTest, compare_list_with_empty_list_right)
{
	int s;
	EXPECT_EQ(false, l2 == z);
}