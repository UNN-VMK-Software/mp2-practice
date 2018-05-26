#include "gtest.h"
#include "Table.h"
#include "ScanTable.h"
#include "SortedTable.h"
#include "HashTable.h"

TEST(ScanTable, can_create_ScanTable) 
{
	ScanTable A(5);
	TPolinom a("1");
	ASSERT_NO_THROW(A.Insert("1", &a));
}

TEST(SortedTable, can_create_SortedTable)
{
	SortedTable A(5);
	TPolinom a("1");
	ASSERT_NO_THROW(A.Insert("1", &a));
}

TEST(HashTable, can_create_HashTable)
{
	HashTable A(5);
	TPolinom a("1");
	ASSERT_NO_THROW(A.Insert("1", &a));
}

class TableTest : public ::testing::Test
{
public:
	HashTable HashT;
	SortedTable SorT;
	ScanTable ScanT;

	TableTest() : HashT(5), SorT(5), ScanT(5)
	{
		HashT.Insert("x", &TPolinom("x"));
		SorT.Insert("x", &TPolinom("x"));
		ScanT.Insert("x", &TPolinom("x"));
		HashT.Insert("y", &TPolinom("y"));
		SorT.Insert("y", &TPolinom("y"));
		ScanT.Insert("y", &TPolinom("y"));
		HashT.Insert("z", &TPolinom("z"));
		SorT.Insert("z", &TPolinom("z"));
		ScanT.Insert("z", &TPolinom("z"));
	};

};

TEST_F(TableTest, can_insert_ScanTable)
{
	TPolinom p("xyz");
	ASSERT_NO_THROW(ScanT.Insert("xyz", &p));
}

TEST_F(TableTest, can_insert_SorT)
{
	TPolinom p("xyz");
	ASSERT_NO_THROW(SorT.Insert("xyz", &p));
}

TEST_F(TableTest, can_insert_HashT)
{
	TPolinom p("xyz");
	ASSERT_NO_THROW(HashT.Insert("xyz", &p));
}

TEST_F(TableTest, can_delete_ScanTable)
{
	TPolinom p("xyz");
	ScanT.Insert("xyz", &p);
	ASSERT_NO_THROW(ScanT.Delete("xyz"));
}

TEST_F(TableTest, can_delete_SorT)
{
	TPolinom p("xyz");
	SorT.Insert("xyz", &p);
	ASSERT_NO_THROW(SorT.Delete("xyz"));
}

TEST_F(TableTest, can_delete_HashT)
{
	TPolinom p("xyz");
	HashT.Insert("xyz", &p);
	ASSERT_NO_THROW(HashT.Delete("xyz"));
}

TEST_F(TableTest, can_search_in_ScanTable)
{
	ASSERT_NO_THROW(ScanT.Search("x"));
}

TEST_F(TableTest, can_search_in_SorT)
{
	ASSERT_NO_THROW(SorT.Search("x"));
}

TEST_F(TableTest, can_search_in_HashT)
{
	ASSERT_NO_THROW(HashT.Search("x"));
}

TEST_F(TableTest, can_reser_in_ScanT)
{
	ScanT.Reset();
	EXPECT_EQ(ScanT.GetIndex(), 0);
}

TEST_F(TableTest, can_reser_in_SorT)
{
	SorT.Reset();
	EXPECT_EQ(SorT.GetIndex(), 0);
}

TEST_F(TableTest, can_reser_in_HashT)
{
	HashT.Reset();
	EXPECT_EQ(HashT.GetIndex(), 0);
}

TEST_F(TableTest, isfull_true_ScanT)
{
	ScanT.Insert("1", &TPolinom("1"));
	ScanT.Insert("2", &TPolinom("2"));
	EXPECT_EQ(ScanT.IsFull(), true);
}

TEST_F(TableTest, isfull_true_SorT)
{
	SorT.Insert("1", &TPolinom("1"));
	SorT.Insert("2", &TPolinom("2"));
	EXPECT_EQ(SorT.IsFull(), true);
}

TEST_F(TableTest, next_true_ScanT)
{
	ScanT.Reset();
	EXPECT_EQ(ScanT.GetIndex(), 1);
}

TEST_F(TableTest, next_true_SorT)
{
	SorT.Reset();
	EXPECT_EQ(SorT.GetIndex(), 1);
}

TEST_F(TableTest, next_true_HashT)
{
	HashT.Reset();
	EXPECT_EQ(HashT.GetIndex(), 1);
}

TEST_F(TableTest, can_get_current_ScanT)
{
	ScanT.Reset();
	unit tmp("x", &TPolinom("x"));
	EXPECT_EQ(ScanT.GetCurrent(), tmp);
}

TEST_F(TableTest, can_get_current_SorT)
{
	SorT.Reset();
	unit tmp("x", &TPolinom("x"));
	EXPECT_EQ(SorT.GetCurrent(), tmp);
}

TEST_F(TableTest, can_get_current_ScanT)
{
	ScanT.Reset();
	unit tmp("z", &TPolinom("z"));
	EXPECT_EQ(ScanT.GetCurrent(), tmp);
}

TEST_F(TableTest, can_get_current_HashT)
{
	HashT.Reset();
	unit tmp("x", &TPolinom("x"));
	EXPECT_EQ(HashT.GetCurrent(), tmp);
}

TEST_F(TableTest, can_get_size_ScanT)
{
	EXPECT_EQ(ScanT.GetSize(), 3);
}

TEST_F(TableTest, can_get_size_SorT)
{
	EXPECT_EQ(SorT.GetSize(), 3);
}

TEST_F(TableTest, can_get_size_HashT)
{
	EXPECT_EQ(HashT.GetSize(), 3);
}

TEST_F(TableTest, can_get_max_size_ScanT)
{
	EXPECT_EQ(ScanT.GetMaxSize(), 5);
}

TEST_F(TableTest, can_get_max_size_SorT)
{
	EXPECT_EQ(SorT.GetMaxSize(), 5);
}

TEST_F(TableTest, can_get_max_size_HashT)
{
	EXPECT_EQ(HashT.GetMaxSize(), 5);
}