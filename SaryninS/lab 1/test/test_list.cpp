#include <gtest.h>
#include "node.h"
#include "list.h"

TEST(Node, can_create_node)
{
	ASSERT_NO_THROW(Node<int> N);
}

TEST(List, can_create_List)
{
	ASSERT_NO_THROW(List<int> L);
}

class EmptyList : public testing::Test
{
protected:
	List<int> L;
public:
	EmptyList() {};
	~EmptyList() {};
};

TEST_F(EmptyList, new_list_is_empty)
{
	EXPECT_EQ(NULL, L.GetCurr()->data);
}

TEST_F(EmptyList, can_copy_empty_list)
{
	ASSERT_NO_THROW(List<int> L2(L));
}

TEST_F(EmptyList, copied_empty_list_is_correct)
{
	List<int> L2(L);
	EXPECT_EQ(NULL, L2.GetCurr()->data);
}

TEST_F(EmptyList, two_empty_lists_are_eq)
{
	List<int> L2;
	EXPECT_EQ(true, L == L2);
}

TEST_F(EmptyList, can_assign_empty_lists)
{
	List<int> L2;
	ASSERT_NO_THROW(L = L2);
}

TEST_F(EmptyList, can_assign_itself_an_empty_list)
{
	ASSERT_NO_THROW(L = L);
}

TEST_F(EmptyList, can_clean_empty_list)
{
	ASSERT_NO_THROW(L.Clean());
}


TEST_F(EmptyList, clean_empty_list_is_correct)
{
	L.Clean();
	EXPECT_EQ(NULL, L.GetCurr()->data);
}

TEST_F(EmptyList, can_get_current_from_empty_list)
{
	ASSERT_NO_THROW(L.GetCurr());
}

TEST_F(EmptyList, can_reset_empty_list)
{
	ASSERT_NO_THROW(L.Reset());
}

TEST_F(EmptyList, is_end_is_correct)
{
	EXPECT_EQ(true, L.IsEnded());
}

TEST_F(EmptyList, can_set_next_empty_list)
{
	ASSERT_NO_THROW(L.GetNext());
}

TEST_F(EmptyList, can_insert_after_in_empty_list)
{	
	L.Reset();
	ASSERT_NO_THROW(L.InsertAfter(L.GetCurr(), 1));

}

TEST_F(EmptyList, insert_after_in_empty_list_is_correct)
{	
	L.Reset();
	L.InsertAfter(L.GetCurr(), 5);
	L.Reset();
	int tmp = L.GetCurr()->data;
	EXPECT_EQ(5, tmp);
}