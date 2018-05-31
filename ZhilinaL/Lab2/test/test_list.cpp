#include "List.h"
#include "gtest.h"

class Test_Lists : public testing::Test
{
protected:
	list <int> l1;
	list<int> l2;
public:
	Test_Lists() { l2.Insert(2), l2.Insert(5); }
	~Test_Lists() {};
};

TEST_F(Test_Lists, can_create_list)
{
	ASSERT_NO_THROW(list<int> l);
}


TEST_F(Test_Lists, can_copy_empty_list)
{
	ASSERT_NO_THROW(list<int> l(l1));
}
TEST_F(Test_Lists, empty_list_copy_is_correct)
{
	list<int> l(l1);
	EXPECT_NE(l1.GetCur(), l.GetCur());
}


TEST_F(Test_Lists, can_assign_empty_list)
{
	ASSERT_NO_THROW(list<int> l = l1);
}

TEST_F(Test_Lists, assigned_empty_list_is_correct)
{
	list<int> l = l1;
	EXPECT_NE(l1.GetCur(), l.GetCur());
}


TEST_F(Test_Lists, can_compare_list_with_itself)
{
	EXPECT_EQ(true, l2 == l2);
}

TEST_F(Test_Lists, empty_lists_are_equal)
{
	list<int> l(l1);
	EXPECT_EQ(true, l == l1);
}

TEST_F(Test_Lists, can_insert_in_empty_list)
{
	ASSERT_NO_THROW(l1.Insert(7));
}

TEST_F(Test_Lists, insert_in_empty_list_is_correct_1)
{
	l1.Insert(7);
	l1.Reset();
	EXPECT_EQ(l1.GetCur(),l1.GetCur()->next->next);
}


TEST_F(Test_Lists, insert_in_empty_list_is_correct_2)
{
	l1.InsertToTail(7);
	l1.Reset();
	EXPECT_EQ(7, l1.GetCur()->data);
}
TEST_F(Test_Lists, can_insert_to_tail_for_empty_list)
{
	ASSERT_NO_THROW(l1.InsertToTail(7));
}
TEST_F(Test_Lists, insert_to_tail_for_empty_list_is_correct_1)
{
	l1.InsertToTail(7);
	l1.Reset();
	EXPECT_EQ(l1.GetCur(), l1.GetCur()->next->next);
}
TEST_F(Test_Lists, insert_to_tail_for_empty_list_is_correct_2)
{
	l1.InsertToTail(7);
	l1.Reset();
	EXPECT_EQ(7, l1.GetCur()->data);
}
//не пустые
TEST_F(Test_Lists, can_copy_not_empty_list)
{
	ASSERT_NO_THROW(list<int> l(l2));
}

TEST_F(Test_Lists, not_empty_list_copy_is_correct)
{
	list<int> l(l2);
	EXPECT_NE(l2.GetCur(), l.GetCur());
}

TEST_F(Test_Lists, not_empty_list_is_copied_correctly_2)
{
	list<int> l(l2);
	l.Reset();
	EXPECT_EQ(2, l.GetCur()->data);
	EXPECT_EQ(5, l.GetCur()->next->data);
}

TEST_F(Test_Lists, can_assign_not_empty_list)
{
	ASSERT_NO_THROW(list<int> l = l2);
}


TEST_F(Test_Lists, assigned_not_empty_list_is_correct_1)
{
	list<int> l = l2;
	EXPECT_NE(l.GetCur(), l2.GetCur());
}


TEST_F(Test_Lists, assigned_not_empty_list_is_correct_2)
{
	list<int> l = l2;
	EXPECT_EQ(l.GetCur(), l.GetCur()->next->next->next);
}

TEST_F(Test_Lists, assigned_not_empty_list_is_correct_3)
{
	list<int> l = l2;
	l.Reset();
	EXPECT_EQ(2, l.GetCur()->data);
	EXPECT_EQ(5, l.GetCur()->next->data);
}

TEST_F(Test_Lists, same_not_empty_lists_are_equal)
{
	list<int> l(l2);
	EXPECT_EQ(true, l == l2);
}

TEST_F(Test_Lists, not_empty_and_empty_lists_are_not_equal)
{
	EXPECT_EQ(false, l2 == l1);
}
TEST_F(Test_Lists, not_same__not_empty_lists_are_not_equal_1)
{
	list<int> l;
	l.Insert(1);
	l.Insert(9);
	EXPECT_EQ(false, l == l2);
}
TEST_F(Test_Lists, not_same__not_empty_lists_are_not_equal_2)
{
	list<int> l;
	l.Insert(1);
	l.Insert(9);
	EXPECT_EQ(true, l != l2);
}
TEST_F(Test_Lists, checking_ending_of_emty_list_is_correct)
{
	EXPECT_EQ(false, l1.IsNotOver());//?????????????????????????
}
TEST_F(Test_Lists, checking_ending_of__not_emty_list_is_correct)
{
	EXPECT_EQ(false,l2.IsNotOver());
}
TEST_F(Test_Lists, insert_to_the_beginning_is_correct_1)
{
	l2.Insert(2);
	EXPECT_EQ(l2.GetCur()->next->next->next->next, l2.GetCur());
}
TEST_F(Test_Lists, insert_to_the_beginning_is_correct_2)
{
	l2.Insert(0);
	l2.Reset();
	EXPECT_EQ(0, l2.GetCur()->data);
	EXPECT_EQ(2, l2.GetCur()->next->data);
	EXPECT_EQ(5, l2.GetCur()->next->next->data);
}
TEST_F(Test_Lists, insert_in_the_middle_is_correct)
{
	l2.Insert(3);
	l2.Reset();
	EXPECT_EQ(2, l2.GetCur()->data);
	EXPECT_EQ(3, l2.GetCur()->next->data);
	EXPECT_EQ(5, l2.GetCur()->next->next->data);
}
TEST_F(Test_Lists, insert_in_the_end_is_correct)
{
	l2.Insert(8);
	l2.Reset();
	EXPECT_EQ(2, l2.GetCur()->data);
	EXPECT_EQ(5, l2.GetCur()->next->data);
	EXPECT_EQ(8, l2.GetCur()->next->next->data);
}
