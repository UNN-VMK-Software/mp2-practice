#include "sorted_table.h"
#include "polinom.h"
#include <gtest.h>

TEST(SortedTable, can_create_table1)
{
	ASSERT_NO_THROW(SortedTable<TPolinom> t(5));
}

TEST(SortedTable, can_create_table2)
{
	ASSERT_NO_THROW(SortedTable<TPolinom> t);
}


TEST(SortedTable, can_copied_table1)
{
	SortedTable<TPolinom> t(5);
	ASSERT_NO_THROW(SortedTable<TPolinom> tt(t));
}

TEST(SortedTable, can_copied_table2)
{
	SortedTable<TPolinom> t;
	ASSERT_NO_THROW(SortedTable<TPolinom> tt(t));
} 

TEST(SortedTable, can_insert_zap1)
{
	SortedTable<TPolinom> t;
	TPolinom tt("2x");
	ASSERT_NO_THROW(t.Insert(tt, "2xy+1"));
}

TEST(SortedTable, can_insert_zap2)
{
	SortedTable<TPolinom> t;
	TPolinom tt("2x+1");
	t.Insert(tt, "2");
	TPolinom ttt("3x");
	ASSERT_ANY_THROW(t.Insert(ttt, "2"));
}

TEST(SortedTable, can_reset1)
{
	SortedTable<TPolinom> t;
	TPolinom tt("2x+1");
	t.Insert(tt, "2");
	TPolinom ttt("2x");
	t.Insert(ttt, "3");
	t.Reset();
	EXPECT_EQ(t.Getcurrind(), 0);
}

TEST(SortedTable, can_reset2)
{
	SortedTable<TPolinom> t;
	t.Reset();
	EXPECT_EQ(t.Getcurrind(), -1);
}

TEST(SortedTable, can_search1)
{
	SortedTable<TPolinom> t;
	ASSERT_ANY_THROW(t.Search("2"));
}

/*TEST(SortedTable, can_search2)
{
	SortedTable<TPolinom> t(3);
	TPolinom tt("2x+1");
	t.Insert(tt, "2");
	TPolinom ttt("2x");
	t.Insert(ttt, "3");
	ASSERT_ANY_THROW(t.Search("5"));
} */

TEST(SortedTable, can_search3)
{
	SortedTable<TPolinom> t(3);
	TPolinom tt("2x+1");
	t.Insert(tt, "2");
	TPolinom ttt("2x");
	t.Insert(ttt, "3");
	EXPECT_EQ(t.Search("3"), ttt);
}

TEST(SortedTable, can_delete1)
{
	SortedTable<TPolinom> t;
	ASSERT_ANY_THROW(t.Delete("2"));
}

/*TEST(SortedTable, can_delete2)
{
	SortedTable<TPolinom> t(1);
	TPolinom tt("2x+1");
	t.Insert(tt, "2");
	t.Delete("2");
	EXPECT_EQ(t.Getcurrrec(), 0);
}*/

/*TEST(SortedTable, can_delete3)
{
	SortedTable<TPolinom> t(2);
	TPolinom tt("2x+1");
	t.Insert(tt, "2");
	TPolinom ttt("2x");
	t.Insert(ttt, "3");
	t.Delete("3");
	EXPECT_EQ(t.Getcurrrec(), 1);
} */






