#include "scan_table.h"
#include <gtest.h>

TEST(ScanTable, can_create_ScanTable_table)
{
	ASSERT_NO_THROW(ScanTable<int> T);
}

//---------------------------------------------------------
class EmptyScanTable : public testing::Test
{
protected:
	ScanTable<int> Tab;
public:
	EmptyScanTable() {};
	~EmptyScanTable() {};
};

TEST_F(EmptyScanTable, empty_ScanTable_tab_is_empty)
{
	EXPECT_EQ(true, Tab.isended());
}

TEST_F(EmptyScanTable, copy_empty_ScanTable_tab_and_correct)
{

	ASSERT_NO_THROW(ScanTable<int> Tab1(Tab));
	ScanTable<int> Tab1(Tab);
	EXPECT_EQ(true, Tab1.isended());
}

TEST_F(EmptyScanTable, cant_getcurr_empty)
{
	ASSERT_ANY_THROW(Tab.GetCurr());
}

TEST_F(EmptyScanTable, can_reset_empty)
{
	ASSERT_NO_THROW(Tab.reset());
	Tab.reset();
	ASSERT_ANY_THROW(Tab.GetCurr());
}

TEST_F(EmptyScanTable, cant_setnext_empty)
{
	ASSERT_ANY_THROW(Tab.SetNext());
}

TEST_F(EmptyScanTable, cant_delete_empty)
{
	ASSERT_ANY_THROW(Tab.Delete("p"));
}

TEST_F(EmptyScanTable, cant_search_empty)
{
	ASSERT_ANY_THROW(Tab.Search("p"));
}

TEST_F(EmptyScanTable, can_insert_empty)
{
	ASSERT_NO_THROW(Tab.Insert("first", 1));
	EXPECT_EQ(1, Tab.GetCurr());
	EXPECT_EQ(1, Tab.Search("first"));
}

//---------------------------------------------------------
class FilledScanTable : public testing::Test
{
protected:
	ScanTable<int> Tab;
public:
	FilledScanTable() {
		Tab.Insert("1", 1);
		Tab.Insert("2", 2);
		Tab.Insert("3", 3);
	};
	~FilledScanTable() {};
};

TEST_F(FilledScanTable, can_reset_filled)
{
	ASSERT_NO_THROW(Tab.reset());
}

TEST_F(FilledScanTable, can_getcurr_filled)
{
	Tab.reset();
	ASSERT_NO_THROW(Tab.GetCurr());
	EXPECT_EQ(1, Tab.GetCurr());
}

TEST_F(FilledScanTable, can_setnext_filled)
{
	Tab.reset();
	ASSERT_NO_THROW(Tab.SetNext());
	EXPECT_EQ(2, Tab.GetCurr());
}

TEST_F(FilledScanTable, setnext_isend_and_correct_table)
{
	Tab.reset();
	EXPECT_EQ(1, Tab.GetCurr());
	Tab.SetNext();
	EXPECT_EQ(2, Tab.GetCurr());
	Tab.SetNext();
	EXPECT_EQ(3, Tab.GetCurr());
	Tab.SetNext();
	EXPECT_EQ(1, Tab.GetCurr());
}

TEST_F(FilledScanTable, can_copy_and_correct)
{
	ASSERT_NO_THROW(ScanTable<int> Tab1(Tab));
	ScanTable<int> Tab1(Tab);
	Tab1.reset();
	EXPECT_EQ(1, Tab1.GetCurr());
	Tab1.SetNext();
	EXPECT_EQ(2, Tab1.GetCurr());
	Tab1.SetNext();
	EXPECT_EQ(3, Tab1.GetCurr());
	Tab1.SetNext();
	EXPECT_EQ(1, Tab1.GetCurr());
}

TEST_F(FilledScanTable, can_delete_and_correct)
{
	Tab.reset();
	ASSERT_NO_THROW(Tab.Delete("1"));
	Tab.reset();
	EXPECT_EQ(3, Tab.GetCurr());
}

TEST_F(FilledScanTable, copy_tab_is_own_memory)
{	Tab.reset();
	ScanTable<int> Tab1(Tab);
	Tab.Delete("1");
	EXPECT_NE(Tab.GetCurr(), Tab1.GetCurr());
}

TEST_F(FilledScanTable, can_realloc)
{
	for (int i = 3; i < 10; i++)
		Tab.Insert(to_string(i + 1), (i + 1));
	ASSERT_NO_THROW(Tab.Insert("11", 11));
}

TEST_F(FilledScanTable, can_insert_after_deletion)
{
	Tab.Delete("1");
	Tab.Delete("2");
	Tab.Delete("3");
	Tab.Insert("1", 0);
	EXPECT_EQ(0, Tab.GetCurr());
}

TEST_F(FilledScanTable, can_search)
{
	ASSERT_NO_THROW(Tab.Search("2"));
	EXPECT_EQ(2, Tab.Search("2"));
}

TEST_F(FilledScanTable, can_insret_exect)
{
	ASSERT_ANY_THROW(Tab.Insert("2", 2));
}