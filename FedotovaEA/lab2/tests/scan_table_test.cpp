#include "scan_table.h"
#include "polinom.h"
#include <gtest.h>

TEST(Scantable, can_create_table1)
{
	ASSERT_NO_THROW(Scantable<TPolinom> t(5));
}

TEST(Scantable, can_create_table2)
{
	ASSERT_NO_THROW(Scantable<TPolinom> t);
}


TEST(Scantable, can_copied_table1)
{
	Scantable<TPolinom> t(5);
	ASSERT_NO_THROW(Scantable<TPolinom> tt(t));
}

TEST(Scantable, can_copied_table2)
{
	Scantable<TPolinom> t;
	ASSERT_NO_THROW(Scantable<TPolinom> tt(t));
}

TEST(Scantable, can_insert_zap1)
{
	Scantable<TPolinom> t;
	TPolinom tt("2x");
	ASSERT_NO_THROW(t.Insert(tt, "2xy+1"));
}

TEST(Scantable, can_insert_zap2)
{
	Scantable<TPolinom> t;
	TPolinom tt("2x+1");
	t.Insert(tt, "2");
	TPolinom ttt("3x");
	ASSERT_ANY_THROW(t.Insert(ttt, "2"));
}

TEST(Scantable, can_reset1)
{
	Scantable<TPolinom> t;
	TPolinom tt("2x+1");
	t.Insert(tt, "2");
	TPolinom ttt("2x");
	t.Insert(ttt, "3");
	t.Reset();
	EXPECT_EQ(t.Getcurrind(), 0);
}

TEST(Scantable, can_reset2)
{
	Scantable<TPolinom> t;
	t.Reset();
	EXPECT_EQ(t.Getcurrind(), -1);
}

TEST(Scantable, can_search1)
{
	Scantable<TPolinom> t;
	ASSERT_ANY_THROW(t.Search("2"));
}

/*TEST(Scantable, can_search2)
{
	Scantable<TPolinom> t;
	TPolinom tt("2x+1");
	t.Insert(tt, "2");
	TPolinom ttt("2x");
	t.Insert(ttt, "3");
	ASSERT_ANY_THROW(t.Search("1"));
}*/

TEST(Scantable, can_search3)
{
	Scantable<TPolinom> t(3);
	TPolinom tt("2x+1");
	t.Insert(tt, "2");
	TPolinom ttt("2x");
	t.Insert(ttt, "3");
	EXPECT_EQ(t.Search("3"), ttt);
}

TEST(Scantable, can_delete1)
{
	Scantable<TPolinom> t;
	ASSERT_ANY_THROW(t.Delete("2"));
}

TEST(Scantable, can_delete2)
{
	Scantable<TPolinom> t(1);
	TPolinom tt("2x+1");
	t.Insert(tt, "2");
	t.Delete("2");
	EXPECT_EQ(t.Getcurrrec(), 0);
}

TEST(Scantable, can_delete3)
{
	Scantable<TPolinom> t(2);
	TPolinom tt("2x+1");
	t.Insert(tt, "2");
	TPolinom ttt("2x");
	t.Insert(ttt, "3");
	t.Delete("3");
	EXPECT_EQ(t.Getcurrrec(), 1);
}


