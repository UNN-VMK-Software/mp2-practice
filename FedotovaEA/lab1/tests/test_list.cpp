#include "node.h"
#include "list.h"
#include <gtest.h>

TEST(Node, can_create_empty_node)
{
	ASSERT_NO_THROW(Node<int> a);
}

TEST(Node, can_create_node_with_data)
{
	Node<int> a(20);
	EXPECT_EQ(a.data, 20);
}

TEST(Node, can_create_copied_node)
{
	Node<int> a;
	Node<int> b(a);
	EXPECT_EQ(b, a);
}

TEST(Node, can_assign)
{
	Node<int> a;
	Node<int> b(5);
	a = b;
	EXPECT_EQ(a.data, 5);
}

TEST(TRinglist, can_create_empty_list)
{
	ASSERT_NO_THROW(TRinglist<int> a);
}

TEST(TRinglist, can_compare_equall)
{
	TRinglist<int> a;
	a.Insert_Up(2);
	TRinglist<int> b;
	b = a;
	EXPECT_EQ(b == a, true);
}

TEST(TRinglist, can_create_copied)
{
	TRinglist<int> b;
	b.Insert_Up(2);
	TRinglist<int> c(b);
	EXPECT_EQ(c, b);
}

TEST(TRinglist, can_compare_not_equall)
{
	TRinglist<int> a, b;
	a.Insert_Up(2);
	b.Insert_Up(3);
	EXPECT_NE(b == a, true);
}

TEST(TRinglist, can_insert_up)
{
	TRinglist<int> a;
	a.Insert_Up(2);
	a.Reset();
	a.Getnext();
	EXPECT_EQ(a.Getdata(), 2);
}

TEST(TRinglist, can_insert_to_tail)
{
	TRinglist<int> a;
	a.Insert_to_tail(2);
	a.Reset();
	a.Getnext();
	EXPECT_EQ(a.Getdata(), 2);
}

TEST(TRinglist, can_clean)
{
	TRinglist<int> a;
	a.Insert_to_tail(5);
	ASSERT_NO_THROW(a.Clean());
}

TEST(TRinglist, can_delete_elem)
{
	TRinglist<int> a;
	a.Insert_Up(2);
	a.Insert_Up(3);
	a.del(a.search(3));
	a.Reset();
	a.Getnext();
	EXPECT_EQ(a.Getdata(), 2);
}

TEST(TRinglist, can_assign)
{
	TRinglist<int> a, b;
	a.Insert_to_tail(3);
	b.Insert_to_tail(1);
	b = a;
	b.Reset();
	b.Getnext();
	EXPECT_EQ(b.Getdata(), 3);
}
