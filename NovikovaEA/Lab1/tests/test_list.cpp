#include "node.h"
#include "list.h"
#include <gtest.h>

TEST(node, create_empty_node)
{
	ASSERT_NO_THROW(node<int> a);
}

TEST(node, create_node_data)
{
	node<int> a(5);
	EXPECT_EQ(a.data, 5);
}

TEST(node, create_copy_node)
{
	node<int> a;
	node<int> b(a);
	EXPECT_EQ(b, a);
}

TEST(node, can_assign)
{
	node<int> a;
	node<int> b(3);
	a = b;
	EXPECT_EQ(a.data, 3);
}

TEST(ringlist, create_empty_list)
{
	ASSERT_NO_THROW(ringlist<int> a);
}

TEST(ringlist, equality)
{
	ringlist<int> a;
	a.insert_up(3);
	ringlist<int> b;
	b = a;
	EXPECT_EQ(b == a, true);
}

TEST(TRinglist, create_copied)
{
	ringlist<int> b;
	b.insert_up(3);
	ringlist<int> c(b);
	EXPECT_EQ(c, b);
}

TEST(ringlist, not_equall)
{
	ringlist<int> a, b;
	a.insert_up(2);
	b.insert_up(3);
	EXPECT_NE(b == a, true);
}

TEST(ringlist, insert_up)
{
	ringlist<int> a;
	a.insert_up(10);
	a.reset();
	a.getnext();
	EXPECT_EQ(a.getdata(), 10);
}

TEST(ringlist, insert_to_tail)
{
	ringlist<int> a;
	a.insert_to_tail(10);
	a.reset();
	a.getnext();
	EXPECT_EQ(a.getdata(), 10);
}

TEST(ringlist, clean)
{
	ringlist<int> a;
	a.insert_to_tail(10);
	ASSERT_NO_THROW(a.clean());
}

TEST(ringlist, delet)
{
	ringlist<int> a;
	a.insert_up(2);
	a.insert_up(3);
	a.delet(a.search(3));
	a.reset();
	a.getnext();
	EXPECT_EQ(a.getdata(), 2);
}

TEST(ringlist, can_assign)
{
	ringlist<int> a, b;
	a.insert_to_tail(3);
	b.insert_to_tail(1);
	b = a;
	b.reset();
	b.getnext();
	EXPECT_EQ(b.getdata(), 3);
}



