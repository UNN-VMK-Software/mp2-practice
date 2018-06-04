#include "gtest.h"
#include "list.h"



class Test_List : public ::testing::Test 
{
protected:
	list<int> A;
	list<int> B;
public:
	Test_List() { B.Insert(5); B.Insert(1);}
	~Test_List() {}
};


// Пустой список

TEST(lists, can_create_empty_list)
{
	ASSERT_NO_THROW(list<int> l);
}

TEST_F(Test_List, created_empty_list_is_empty)
{
	EXPECT_EQ(true, !A.IsNotOver());
}


TEST_F(Test_List, can_copy_empty_list)
{
	ASSERT_NO_THROW(list<int> l(A));
}


TEST_F(Test_List, empty_list_copy_is_correct_1)
{
	list<int> l(A);
	EXPECT_NE(A.GetAct(), l.GetAct());
}

TEST_F(Test_List, empty_list_copy_is_correct_2)
{
	list<int> l(A);
	EXPECT_EQ(true, !A.IsNotOver());
}


TEST_F(Test_List, can_assign_empty_list)
{
	ASSERT_NO_THROW(list<int> l = A);
}

TEST_F(Test_List, assigned_empty_list_is_correct)
{
	list<int> l = A;
	EXPECT_NE(A.GetAct(), l.GetAct());                                  
}


TEST_F(Test_List, can_compare_list_with_itself)
{
	EXPECT_EQ(true, A == A);
}

TEST_F(Test_List, empty_lists_are_equal)
{
	list<int> l(A);
	EXPECT_EQ(true, l == A);
}

TEST_F(Test_List, can_insert_in_empty_list)
{
	ASSERT_NO_THROW(A.Insert(7));
}

TEST_F(Test_List, insert_in_empty_list_is_correct_1)
{
	A.Insert(7);
	A.Reset();
	EXPECT_EQ(A.GetAct(), A.GetAct() -> next -> next );
}


TEST_F(Test_List, insert_in_empty_list_is_correct_2)
{
	A.Insert(7);
	A.Reset();
	EXPECT_EQ(7, A.GetAct() -> data);
}


// Непустой список

TEST_F(Test_List, can_copy_not_empty_list)
{
	ASSERT_NO_THROW(list<int> l(B));
}

TEST_F(Test_List, not_empty_list_is_copied_correctly_1)
{
	list<int> l(B);
	EXPECT_NE(B.GetAct(), l.GetAct());
}

TEST_F(Test_List, not_empty_list_is_copied_correctly_2)
{
	list<int> l(B);
	EXPECT_EQ(l.GetAct(), l.GetAct()->next->next->next);
}

TEST_F(Test_List, not_empty_list_is_copied_correctly_3)
{
	list<int> l(B);
	l.Reset();
	EXPECT_EQ(1, l.GetAct()->data);
	EXPECT_EQ(5, l.GetAct()->next->data);
}

TEST_F(Test_List, can_assign_not_empty_list)
{
	ASSERT_NO_THROW(list<int> l = B);
}


TEST_F(Test_List, assigned_not_empty_list_is_correct_1)
{
	list<int> l = B;
	EXPECT_NE(l.GetAct(), B.GetAct());
}


TEST_F(Test_List, assigned_not_empty_list_is_correct_2)
{
	list<int> l = B;
	EXPECT_EQ(l.GetAct(), l.GetAct()->next->next->next);
}

TEST_F(Test_List, assigned_not_empty_list_is_correct_3)
{
	list<int> l = B;
	l.Reset();
	EXPECT_EQ(1, l.GetAct()->data);
	EXPECT_EQ(5, l.GetAct()->next->data);
}

TEST_F(Test_List, not_empty_lists_are_equal)
{
	list<int> l(B);
	EXPECT_EQ(true, l == B);
}

TEST_F(Test_List, not_empty_and_empty_lists_are_not_equal)
{
	EXPECT_EQ(false, B == A);
}

TEST_F(Test_List, insert_to_the_beginning_1)
{
	B.Insert(0);
	EXPECT_EQ(B.GetAct()->next->next->next->next, B.GetAct());
}

TEST_F(Test_List, insert_to_the_beginning_2)
{
	B.Insert(0);
	B.Reset();
	EXPECT_EQ(0, B.GetAct()->data);
	EXPECT_EQ(1, B.GetAct()->next->data);
	EXPECT_EQ(5, B.GetAct()->next->next->data);
}

TEST_F(Test_List, insert_in_the_middle_1)
{
	B.Insert(3);
	EXPECT_EQ(A.GetAct()->next->next->next->next, A.GetAct());
}

TEST_F(Test_List, insert_in_the_middle_2)
{
	B.Insert(3);
	B.Reset();
	EXPECT_EQ(1, B.GetAct()->data);
	EXPECT_EQ(3, B.GetAct()->next->data);
	EXPECT_EQ(5, B.GetAct()->next->next->data);
}

TEST_F(Test_List, insert_in_the_end_1)
{
	B.Insert(8);
	EXPECT_EQ(B.GetAct()->next->next->next->next, B.GetAct());
}

TEST_F(Test_List, insert_in_the_end_2)
{
	B.Insert(8);
	B.Reset();
	EXPECT_EQ(1, B.GetAct()->data);
	EXPECT_EQ(5, B.GetAct()->next->data);
	EXPECT_EQ(8, B.GetAct()->next->next->data);
}
