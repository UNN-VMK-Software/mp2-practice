#include "hash_table.h"
#include "polinom.h"
#include <gtest.h>

TEST(Hashtable, can_create_table1)
{
	ASSERT_NO_THROW(Hashtable<TPolinom> t(5));
}

TEST(Hashtable, can_create_table2)
{
	ASSERT_NO_THROW(Hashtable<TPolinom> t);
}


TEST(Hashtable, can_copied_table1)
{
	Hashtable<TPolinom> t(5);
	ASSERT_NO_THROW(Hashtable<TPolinom> tt(t));
}

TEST(Hashtable, can_copied_table2)
{
	Hashtable<TPolinom> t;
	ASSERT_NO_THROW(Hashtable<TPolinom> tt(t));
}

TEST(Hashtable, can_insert_zap1)
{
	Hashtable<TPolinom> t;
	TPolinom tt("2x");
	ASSERT_NO_THROW(t.Insert(tt, "2xy+1"));
}

TEST(Hashtable, can_insert_zap2)
{
	Hashtable<TPolinom> t;
	TPolinom tt("2x+1");
	t.Insert(tt, "2");
	TPolinom ttt("3x");
	ASSERT_ANY_THROW(t.Insert(ttt, "2"));
}

TEST(Hashtable, can_reset1)
{
	Hashtable<TPolinom> t;
	TPolinom tt("2x+1");
	t.Insert(tt, "2");
	TPolinom ttt("2x");
	t.Insert(ttt, "3");
	t.Reset();
	EXPECT_EQ(t.Getcurrind(), 0);
}

TEST(Hashtable, can_reset2)
{
	Hashtable<TPolinom> t;
	t.Reset();
	EXPECT_EQ(t.Getcurrind(), -1);
}

TEST(Hashtable, can_search1)
{
	Hashtable<TPolinom> t;
	ASSERT_ANY_THROW(t.Search("2"));
}

TEST(Hashtable, can_search3)
{
	Hashtable<TPolinom> t(3);
	TPolinom tt("2x+1");
	t.Insert(tt, "2");
	TPolinom ttt("2x");
	t.Insert(ttt, "3");
	EXPECT_EQ(t.Search("3"), ttt);
}

TEST(Hashtable, can_delete1)
{
	Hashtable<TPolinom> t;
	ASSERT_ANY_THROW(t.Delete("2"));
}

TEST(Hashtable, can_delete2)
{
	Hashtable<TPolinom> t(1);
	TPolinom tt("2x+1");
	t.Insert(tt, "2");
	t.Delete("2");
	EXPECT_EQ(t.Getcurrrec(), 0);
}

TEST(Hashtable, can_delete3)
{
	Hashtable<TPolinom> t(2);
	TPolinom tt("2x+1");
	t.Insert(tt, "2");
	TPolinom ttt("2x");
	t.Insert(ttt, "3");
	t.Delete("3");
	EXPECT_EQ(t.Getcurrrec(), 1);
} 