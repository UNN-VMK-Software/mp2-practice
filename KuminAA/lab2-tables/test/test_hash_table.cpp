#include "hash_table.h"
#include <gtest.h>

TEST(HashTable, can_create_HashTable_table)
{
	ASSERT_NO_THROW(HashTable<int> T);
}

//---------------------------------------------------------
class EmptyHashTable : public testing::Test
{
protected:
	HashTable<int> Tab;
public:
	EmptyHashTable() {};
	~EmptyHashTable() {};
};

TEST_F(EmptyHashTable, empty_HashTable_tab_is_empty)
{
	EXPECT_EQ(true, Tab.isended());
}

TEST_F(EmptyHashTable, copy_empty_HashTable_tab_and_correct)
{

	ASSERT_NO_THROW(HashTable<int> Tab1(Tab));
	HashTable<int> Tab1(Tab);
	EXPECT_EQ(true, Tab1.isended());
}

TEST_F(EmptyHashTable, cant_getcurr_empty)
{
	ASSERT_ANY_THROW(Tab.GetCurr());
}

TEST_F(EmptyHashTable, can_reset_empty)
{
	ASSERT_NO_THROW(Tab.reset());
	Tab.reset();
	ASSERT_ANY_THROW(Tab.GetCurr());
}

TEST_F(EmptyHashTable, cant_setnext_empty)
{
	ASSERT_ANY_THROW(Tab.SetNext());
}

TEST_F(EmptyHashTable, cant_delete_empty)
{
	ASSERT_ANY_THROW(Tab.Delete("p"));
}

TEST_F(EmptyHashTable, cant_search_empty)
{
	ASSERT_ANY_THROW(Tab.Search("p"));
}

TEST_F(EmptyHashTable, can_insert_empty)
{
	ASSERT_NO_THROW(Tab.Insert("first", 1));
	EXPECT_EQ(1, Tab.GetCurr());
	EXPECT_EQ(1, Tab.Search("first"));
}

//---------------------------------------------------------
class FilledHashTable : public testing::Test
{
protected:
	HashTable<int> Tab;
public:
	FilledHashTable() {
		Tab.Insert("1", 1);
		Tab.Insert("2", 2);
		Tab.Insert("3", 3);
	};
	~FilledHashTable() {};
};

TEST_F(FilledHashTable, can_reset_filled)
{
	ASSERT_NO_THROW(Tab.reset());
}

TEST_F(FilledHashTable, can_getcurr_filled)
{
	Tab.reset();
	ASSERT_NO_THROW(Tab.GetCurr());
	//EXPECT_EQ(1, Tab.GetCurr());
}

TEST_F(FilledHashTable, can_setnext_filled)
{
	Tab.reset();
	ASSERT_NO_THROW(Tab.SetNext());
	//EXPECT_EQ(2, Tab.GetCurr());
}

TEST_F(FilledHashTable, can_search)
{
	ASSERT_NO_THROW(Tab.Search("2"));
	EXPECT_EQ(2, Tab.Search("2"));
}

TEST_F(FilledHashTable, correct_table)
{
	Tab.reset();
	EXPECT_EQ(1, Tab.Search("1"));
	EXPECT_EQ(2, Tab.Search("2"));
	EXPECT_EQ(3, Tab.Search("3"));
}

TEST_F(FilledHashTable, can_copy_and_correct)
{
	ASSERT_NO_THROW(HashTable<int> Tab1(Tab));
	HashTable<int> Tab1(Tab);
	Tab1.reset();
	EXPECT_EQ(1, Tab1.Search("1"));
	EXPECT_EQ(2, Tab1.Search("2"));
	EXPECT_EQ(3, Tab1.Search("3"));
}

TEST_F(FilledHashTable, can_delete_and_correct)
{
	Tab.reset();
	ASSERT_NO_THROW(Tab.Delete("1"));
	Tab.reset();
	ASSERT_ANY_THROW(Tab.Search("1"));
}

TEST_F(FilledHashTable, copy_tab_is_own_memory)
{
	Tab.reset();
	HashTable<int> Tab1(Tab);
	Tab.Delete("1");
	EXPECT_EQ(1, Tab1.Search("1"));
}

TEST_F(FilledHashTable, can_realloc)
{
	for (int i = 3; i < 10; i++)
		Tab.Insert(to_string(i + 1), (i + 1));
	ASSERT_NO_THROW(Tab.Insert("11", 11));
}

TEST_F(FilledHashTable, can_insert_after_deletion)
{
	Tab.Delete("1");
	Tab.Delete("2");
	Tab.Delete("3");
	Tab.Insert("1", 0);
	EXPECT_EQ(0, Tab.Search("1"));
}



TEST_F(FilledHashTable, can_insert_exect)
{
	ASSERT_ANY_THROW(Tab.Insert("2", 2));
}