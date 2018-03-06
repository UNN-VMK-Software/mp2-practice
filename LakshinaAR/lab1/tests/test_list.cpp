#include "gtest.h"
#include "list.h"


// Всё понятно, надо переписать по-своему и решить проблема :list()

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
	EXPECT_EQ(A.GetHead(), A.GetHead()->next);
}


TEST_F(Test_List, can_copy_empty_list)
{
	ASSERT_NO_THROW(list<int> l(A));
}


TEST_F(Test_List, empty_list_copy_is_correct_1)
{
	list<int> l(A);
	EXPECT_NE(l.GetHead(),A.GetHead());
}

TEST_F(Test_List, empty_list_copy_is_correct_2)
{
	list<int> l(A);
	EXPECT_EQ(l.GetHead()->next, l.GetHead());
}


TEST_F(Test_List, can_assign_empty_list)
{
	ASSERT_NO_THROW(list<int> l = A);
}

TEST_F(Test_List, assigned_empty_list_is_correct_1)
{
	list<int> l = A;
	EXPECT_NE(l.GetHead(), A.GetHead());
}

TEST_F(Test_List, assigned_empty_list_is_correct_2)
{
	list<int> l = A;
	EXPECT_EQ(l.GetHead()->next, l.GetHead());
}

TEST_F(Test_List, can_compare_list_with_itself)
{
	EXPECT_EQ(true, A==A);
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
	EXPECT_EQ(A.GetHead()->next->next, A.GetHead());
}


TEST_F(Test_List, insert_in_empty_list_is_correct_2)
{
	A.Insert(7);
	EXPECT_EQ(7, A.GetHead()->next->data);
}




// Непустой список

TEST_F(Test_List, can_copy_not_empty_list)
{
	ASSERT_NO_THROW(list<int> l(B));
}

TEST_F(Test_List, not_empty_list_is_copied_correctly_1)
{
	list<int> l(B);
	EXPECT_NE(l.GetHead(), B.GetHead());
}

TEST_F(Test_List, not_empty_list_is_copied_correctly_2)
{
	list<int> l(B);
	EXPECT_EQ(l.GetHead(), l.GetHead()->next->next->next);
}

TEST_F(Test_List, not_empty_list_is_copied_correctly_3)
{
	list<int> l(B);
	EXPECT_EQ(1, l.GetHead()->next->data);
	EXPECT_EQ(5, l.GetHead()->next->next->data);
}

TEST_F(Test_List, can_assign_not_empty_list)
{
	ASSERT_NO_THROW(list<int> l = B);
}


TEST_F(Test_List, assigned_not_empty_list_is_correct_1)
{
	list<int> l = B;
	EXPECT_NE(l.GetHead(), B.GetHead());
}


TEST_F(Test_List, assigned_not_empty_list_is_correct_2)
{
	list<int> l = B;
	EXPECT_EQ(l.GetHead(), l.GetHead()->next->next->next);
}

TEST_F(Test_List, assigned_not_empty_list_is_correct_3)
{
	list<int> l = B;
	EXPECT_EQ(1, l.GetHead()->next->data);
	EXPECT_EQ(5, l.GetHead()->next->next->data);
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
	EXPECT_EQ(A.GetHead()->next->next->next->next, A.GetHead());
}

TEST_F(Test_List, insert_to_the_beginning_2)
{
	B.Insert(0);
	EXPECT_EQ(0, B.GetHead()->next->data);
	EXPECT_EQ(1, B.GetHead()->next->next->data);
	EXPECT_EQ(5, B.GetHead()->next->next->next->data);
}

TEST_F(Test_List, insert_in_the_middle_1)
{
	B.Insert(3);
	EXPECT_EQ(A.GetHead()->next->next->next->next, A.GetHead());
}

TEST_F(Test_List, insert_in_the_middle_2)
{
	B.Insert(3);
	EXPECT_EQ(1, B.GetHead()->next->data);
	EXPECT_EQ(3, B.GetHead()->next->next->data);
	EXPECT_EQ(5, B.GetHead()->next->next->next->data);
}

TEST_F(Test_List, insert_in_the_end_1)
{
	B.Insert(8);
	EXPECT_EQ(A.GetHead()->next->next->next->next, A.GetHead());
}

TEST_F(Test_List, insert_in_the_end_2)
{
	B.Insert(8);
	EXPECT_EQ(1, B.GetHead()->next->data);
	EXPECT_EQ(5, B.GetHead()->next->next->data);
	EXPECT_EQ(8, B.GetHead()->next->next->next->data);
}






