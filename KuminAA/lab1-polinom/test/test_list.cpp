#include "list.h"
#include "node.h"
#include <gtest.h>

TEST(Node, can_create_node)
{
	ASSERT_NO_THROW(Node<double> l(0));
}

TEST(Ringlist, can_create_ringlist)
{
	ASSERT_NO_THROW(Ringlist<double> l);
}

//---------------------------------------------------------
class EmptyList : public testing::Test
{
protected:
	Ringlist<double> l;
public:
	EmptyList() {};
	~EmptyList() {};
};

TEST_F(EmptyList, can_GetCurr_from_empty_list)
{
	ASSERT_NO_THROW(l.GetCurr());
	int a = l.GetCurr();
	l.reset();
	EXPECT_EQ(a, l.GetCurr());
}

TEST_F(EmptyList, can_SetNext_from_empty_list)
{
	ASSERT_NO_THROW(l.SetNext());
}

TEST_F(EmptyList, can_reset_from_empty_list)
{
	ASSERT_NO_THROW(l.reset());
}

TEST_F(EmptyList, new_list_is_empty)
{
	EXPECT_EQ(NULL, l.GetCurr());
}


TEST_F(EmptyList, can_isended_from_empty_list)
{
	ASSERT_NO_THROW(l.isended());
	EXPECT_EQ(1, l.isended());
}

TEST_F(EmptyList, can_copy_empty_list)
{
	ASSERT_NO_THROW(Ringlist<double> l1(l));
}

TEST_F(EmptyList, empty_list_copy_is_correct)
{
	Ringlist<double> l1(l);
	EXPECT_EQ(l.GetCurr(), l1.GetCurr());
	EXPECT_EQ(NULL, l1.GetCurr());
}

TEST_F(EmptyList, can_assign_two_empty_lists)
{
	Ringlist<double> l1;
	ASSERT_NO_THROW(l = l1);
	l = l1;
	EXPECT_EQ(l.GetCurr(), l1.GetCurr());
}

TEST_F(EmptyList, can_insert_to_ordered_for_empty_list)
{
	l.InsertToOrdered(1);
	l.InsertToOrdered(2);
	l.reset();
	EXPECT_EQ(2, l.GetCurr());
	l.SetNext();
	EXPECT_EQ(1, l.GetCurr());
}

//-------------------------------------------------------------------------------

class ThreeNodesList : public testing::Test
{
protected:
	Ringlist<double> l;
public:
	ThreeNodesList()
	{
		l.InsertToOrdered(1);
		l.InsertToOrdered(2);
		l.InsertToOrdered(3);
	}
	~ThreeNodesList() {};
};

TEST_F(ThreeNodesList, can_copy_not_empty_list)
{
	ASSERT_NO_THROW(Ringlist<double> l1(l));
}

TEST_F(ThreeNodesList, copy_of_not_empty_list_is_correct)
{
	Ringlist<double> l1(l);
	l.reset();
	l1.reset();
	EXPECT_EQ(3, l1.GetCurr());
	l1.SetNext();
	l.SetNext();
	EXPECT_EQ(2, l1.GetCurr());
	l1.SetNext();
	l.SetNext();
	EXPECT_EQ(1, l1.GetCurr());
	l1.SetNext();
	l.SetNext();
}

TEST_F(ThreeNodesList, can_assign_not_empty_list)
{
	ASSERT_NO_THROW(Ringlist<double> l1 = l);
}

TEST_F(ThreeNodesList, assign_of_not_empty_list_is_correct)
{
	Ringlist<double> l1 = l;
	l.reset();
	l1.reset();
	EXPECT_EQ(3, l1.GetCurr());
	l1.SetNext();
	l.SetNext();
	EXPECT_EQ(2, l1.GetCurr());
	l1.SetNext();
	l.SetNext();
	EXPECT_EQ(1, l1.GetCurr());
	l1.SetNext();
	l.SetNext();
}