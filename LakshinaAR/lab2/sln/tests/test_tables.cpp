#include "gtest.h"
#include "scan_table.h"
#include "sorted_table.h"
#include "hash_table.h"
#include <iostream>
#include "polinom.h"


class Test_table : public testing::Test
{
protected:
	scantable<int> EmptyScanT;   
	scantable<int> ScanT;
	sortedtable<int> EmptySortT;
	sortedtable<int> SortT;
	hashtable<int> EmptyHashT;
	hashtable<int> HashT;

public:
	Test_table() : EmptyScanT(10), ScanT(10), EmptySortT(10), SortT(10), EmptyHashT(10), HashT(10)
	{
		ScanT.Insert("f", 6);
		ScanT.Insert("b", 2);

		SortT.Insert("f", 6);
		SortT.Insert("b", 2);

		HashT.Insert("f", 6);
		HashT.Insert("b", 2);
	}
	~Test_table() {}
};



// SCANTABLE
TEST_F (Test_table, cant_search_missing_element_in_scantable)
{
	ASSERT_ANY_THROW(EmptyScanT.Search("a"));
}

TEST_F (Test_table, insert_search_in_scantable)
{
	EmptyScanT.Insert("e", 5);
	EXPECT_EQ(5, *(EmptyScanT.Search("e")));
}

TEST_F(Test_table, cant_delete_missing_element_in_scantable)
{
	ASSERT_ANY_THROW(EmptyScanT.Delete("a"));
}

TEST_F(Test_table, insert_delete_in_scantable)
{
	EmptyScanT.Insert("e", 5);
	EmptyScanT.Delete("e");
	EXPECT_EQ(true, EmptyScanT.IsEmpty());
}

TEST_F(Test_table, delete_search_in_scantable)
{
	EXPECT_EQ(2, *(ScanT.Search("b")));
	ScanT.Delete("b");
	ASSERT_ANY_THROW(ScanT.Search("b"));
}

TEST_F(Test_table, cant_insert_elements_with_repeated_key_in_scantable)
{
	EmptyScanT.Insert("a", 1);
	ASSERT_ANY_THROW(EmptyScanT.Insert("a", 2););
}

TEST_F(Test_table, correct_navigation_in_empty_scantable_1) 
{
	ASSERT_ANY_THROW(EmptyScanT.Reset());
}

TEST_F(Test_table, correct_navigation_in_empty_scantable_2)
{
	ASSERT_ANY_THROW(EmptyScanT.GetNext());
}

TEST_F(Test_table, correct_navigation_in_empty_scantable_3)
{
	ASSERT_ANY_THROW(EmptyScanT.GetCurrent());
}

TEST_F(Test_table, correct_navigation_in_empty_scantable_4)
{
	EXPECT_EQ(true, EmptyScanT.IsTabEnded());
}

TEST_F(Test_table, correctness_navigation_methods_in_scantable)
{
	ScanT.Reset();
	EXPECT_EQ("f", ScanT.GetCurrent().key);
	EXPECT_EQ(6, *ScanT.GetCurrent().data);

	ScanT.GetNext();
	EXPECT_EQ("b", ScanT.GetCurrent().key);
	EXPECT_EQ(2, *ScanT.GetCurrent().data);

	EXPECT_EQ(true, ScanT.IsTabEnded());

	ScanT.GetNext();
	EXPECT_EQ("f", ScanT.GetCurrent().key);
	EXPECT_EQ(6, *ScanT.GetCurrent().data);
}



//SORTTABLE

TEST_F (Test_table, cant_search_missing_element_in_sortedtable)
{
	ASSERT_ANY_THROW(EmptySortT.Search("a"));
}

TEST_F(Test_table, insert_search_in_sortedtable)
{
	EmptySortT.Insert("e", 5);
	EXPECT_EQ(5, *(EmptySortT.Search("e")));
}

TEST_F(Test_table, cant_delete_missing_element_in_sortedtable)
{
	ASSERT_ANY_THROW(EmptySortT.Delete("a"));
}

TEST_F(Test_table, insert_delete_in_sortedtable)
{
	EmptySortT.Insert("e", 5);
	EmptySortT.Delete("e");
	EXPECT_EQ(true, EmptySortT.IsEmpty());
}

TEST_F(Test_table, delete_search_in_sortedtable)
{
	EXPECT_EQ(2, *(SortT.Search("b")));
	SortT.Delete("b");
	ASSERT_ANY_THROW(SortT.Search("b"));
}

TEST_F(Test_table, cant_insert_elements_with_repeated_key_in_sortedtable)
{
	EmptySortT.Insert("a", 1);
	ASSERT_ANY_THROW(EmptySortT.Insert("a", 2););
}


TEST_F(Test_table, correct_navigation_in_empty_sortedtable_1)   
{
	ASSERT_ANY_THROW(EmptySortT.Reset());
}

TEST_F(Test_table, correct_navigation_in_empty_sortedtable_2)
{
	ASSERT_ANY_THROW(EmptySortT.GetNext());
}

TEST_F(Test_table, correct_navigation_in_empty_sortedtable_3)
{
	ASSERT_ANY_THROW(EmptySortT.GetCurrent());
}

TEST_F(Test_table, correct_navigation_in_empty_sortedtable_4)
{
	EXPECT_EQ(true, EmptySortT.IsTabEnded());
}

TEST_F(Test_table, correctness_navigation_methods_in_sortedtable)
{
	SortT.Reset();
	EXPECT_EQ("b", SortT.GetCurrent().key);
	EXPECT_EQ(2, *SortT.GetCurrent().data);

	SortT.GetNext();
	EXPECT_EQ("f", SortT.GetCurrent().key);
	EXPECT_EQ(6, *SortT.GetCurrent().data);

	EXPECT_EQ(true, SortT.IsTabEnded());

	SortT.GetNext();
	EXPECT_EQ("b", SortT.GetCurrent().key);
	EXPECT_EQ(2, *SortT.GetCurrent().data);
}


//HASHTABLE

TEST_F(Test_table, cant_search_missing_element_in_hashtable)
{
	ASSERT_ANY_THROW(EmptyHashT.Search("a"));
}

TEST_F(Test_table, insert_search_in_hashtable)
{
	EmptyHashT.Insert("e", 5);
	EXPECT_EQ(5, *(EmptyHashT.Search("e")));
}

TEST_F(Test_table, cant_delete_missing_element_in_hashtable)
{
	ASSERT_ANY_THROW(EmptyHashT.Delete("a"));
}

TEST_F(Test_table, insert_delete_in_hashtable)
{
	EmptyHashT.Insert("e", 5);
	EmptyHashT.Delete("e");
	EXPECT_EQ(true, EmptyHashT.IsEmpty());
}

TEST_F(Test_table, delete_search_in_hashtable)
{
	EXPECT_EQ(2, *(HashT.Search("b")));
	HashT.Delete("b");
	ASSERT_ANY_THROW(HashT.Search("b"));
}

TEST_F(Test_table, cant_insert_elements_with_repeated_key_in_hashtable)
{
	EmptyHashT.Insert("a", 1);
	ASSERT_ANY_THROW(EmptyHashT.Insert("a", 2););
}

TEST_F(Test_table, correctness_navigation_methods_in_empty_hashtable)
{
	ASSERT_ANY_THROW(EmptyHashT.Reset());
	EXPECT_EQ(true, EmptyHashT.IsTabEnded());
}


TEST_F(Test_table, correctness_navigation_methods_in_hashdtable)
{
	SortT.Reset();
	EXPECT_EQ("b", SortT.GetCurrent().key);
	EXPECT_EQ(2, *SortT.GetCurrent().data);

	SortT.GetNext();
	EXPECT_EQ("f", SortT.GetCurrent().key);
	EXPECT_EQ(6, *SortT.GetCurrent().data);

	EXPECT_EQ(true, SortT.IsTabEnded());

	SortT.GetNext();
	EXPECT_EQ("b", SortT.GetCurrent().key);
	EXPECT_EQ(2, *SortT.GetCurrent().data);
}

