#include "gtest.h"
#include "ScanTable.h"
#include "SortTable.h"
#include "HashTable.h"

TEST(Table, search_missing_element_in_ScanTable)
{
	ScanTable<int> tab1(5);
	bool p = tab1.Search("a");
	EXPECT_EQ(0, p);
}

TEST(Table, search_missing_element_in_SortTable)
{
	SortTable<int> tab1(5);
	bool p = tab1.Search("a");
	EXPECT_EQ(p,NULL);
}

TEST(Table, search_missing_element_in_HashTable)
{
	HashTable<int> tab1(5);
	ASSERT_ANY_THROW(tab1.Search("a"));
}

TEST(Table, insert_and_search_in_ScanTable)
{
	ScanTable<int> tab1(5);
	tab1.Insert("c", 3);
	EXPECT_EQ(3, *(tab1.Search("c")));
}

TEST(Table, insert_and_search_in_SortTable)
{
	SortTable<int> tab1(5);
	tab1.Insert("c", 3);
	EXPECT_EQ(3, *(tab1.Search("c")));
}

TEST(Table, insert_and_search_in_HashTable)
{
	HashTable<int> tab1(5);
	tab1.Insert("c", 3);
	EXPECT_EQ(3, *(tab1.Search("c")));
}

TEST(Table, delete_missing_element_in_ScanTable)
{
	ScanTable<int> tab1(5);
	ASSERT_ANY_THROW(tab1.Delete("a"));
}

TEST(Table, delete_missing_element_in_SortTable)
{
	SortTable<int> tab1(5);
	ASSERT_ANY_THROW(tab1.Delete("a"));
}

TEST(Table, delete_missing_element_in_HashTable)
{
	HashTable<int> tab1(5);
	ASSERT_ANY_THROW(tab1.Delete("a"));
}

TEST(Table, insert_and_delete_in_ScanTable)
{
	ScanTable<int> tab1(5);
	tab1.Insert("c", 3);
	tab1.Delete("c");
	EXPECT_EQ(true, tab1.Empty());
}

TEST(Table, insert_and_delete_in_SortTable)
{
	SortTable<int> tab1(5);
	tab1.Insert("c", 3);
	tab1.Delete("c");
	EXPECT_EQ(true, tab1.Empty());
}

TEST(Table, insert_and_delete_in_HashTable)
{
	HashTable<int> tab1(5);
	tab1.Insert("c", 3);
	tab1.Delete("c");
	EXPECT_EQ(true, tab1.Empty());
}

TEST(Table, delete_and_search_in_ScanTable)
{
	ScanTable<int> tab1(5);
	tab1.Insert("b", 2);
	EXPECT_EQ(2, *(tab1.Search("b")));
	tab1.Delete("b");
	bool p = tab1.Search("b");
	EXPECT_EQ(p,NULL);
}

TEST(Table, delete_and_search_in_SortTable)
{
	SortTable<int> tab1(5);
	tab1.Insert("b", 2);
	EXPECT_EQ(2, *(tab1.Search("b")));
	tab1.Delete("b");
	bool p = tab1.Search("b");
	EXPECT_EQ(p, NULL);
}

TEST(Table, delete_and_search_in_HashTable)
{
	HashTable<int> tab1(5);
	tab1.Insert("b", 2);
	EXPECT_EQ(2, *(tab1.Search("b")));
	tab1.Delete("b");
	ASSERT_ANY_THROW(tab1.Search("b"));
}

TEST(Table, correct_navigation_methods_in_empty_ScanTable)
{
	ScanTable<int> tab1(5);
	ASSERT_ANY_THROW(tab1.First());
	ASSERT_ANY_THROW(tab1.Next());
	ASSERT_ANY_THROW(tab1.GetCurr());
	EXPECT_EQ(true, tab1.End());
}

TEST(Table, correct_navigation_methods_in_empty_SortTable)
{
	SortTable<int> tab1(5);
	ASSERT_ANY_THROW(tab1.First());
	ASSERT_ANY_THROW(tab1.Next());
	ASSERT_ANY_THROW(tab1.GetCurr());
	EXPECT_EQ(true, tab1.End());
}

TEST(Table, correctness_navigation_methods_in_empty_HashTable)
{
	HashTable<int> tab1(5);
	ASSERT_ANY_THROW(tab1.First());
	EXPECT_EQ(true, tab1.End());
}