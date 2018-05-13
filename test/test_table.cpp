#include "gtest.h"
#include "scantable.h"
#include "sortedtable.h"
#include "hashtable.h"
#include <iostream>
#include "polynom.h"

class Ttab : public testing::Test
{
protected:
	scantable<int> et1;
	scantable<int> t1;
	sortedtable<int> et2;
	sortedtable<int> t2;
	hashtable<int> et3;
	hashtable<int> t3;
	
public:
	Ttab() : et1(5), t1(5), et2(5), t2(5), et3(5), t3(5)
	{				
		t1.Insert("d", 4);
		t1.Insert("b", 2);

		t2.Insert("d", 4);
		t2.Insert("b", 2);
		
		t3.Insert("d", 4);
		t3.Insert("b", 2);
		
	}
	~Ttab() {}
};

TEST_F(Ttab, cant_search_missing_element_in_scantable)
{
	ASSERT_ANY_THROW(et1.Search("a"));
}

TEST_F(Ttab, cant_search_missing_element_in_sortedtable)
{
	ASSERT_ANY_THROW(et2.Search("a"));
}

TEST_F(Ttab, cant_search_missing_element_in_hashtable)
{
	ASSERT_ANY_THROW(et3.Search("a"));
}

TEST_F (Ttab, insert_search_in_scantable)
{
	et1.Insert("c", 3);
	EXPECT_EQ(3, et1.Search("c"));
}

TEST_F(Ttab, insert_search_in_sortedtable)
{
	et2.Insert("c", 3);
	EXPECT_EQ(3, et2.Search("c"));
}

TEST_F(Ttab, insert_search_in_hashtable)
{
	et3.Insert("c", 3);
	EXPECT_EQ(3, et3.Search("c"));
}

TEST_F(Ttab, cant_delete_missing_element_in_scantable)
{
	ASSERT_ANY_THROW(et1.Delete("a"));
}

TEST_F(Ttab, cant_delete_missing_element_in_sortedtable)
{
	ASSERT_ANY_THROW(et2.Delete("a"));
}

TEST_F(Ttab, cant_delete_missing_element_in_hashtable)
{
	ASSERT_ANY_THROW(et3.Delete("a"));
}

TEST_F(Ttab, insert_delete_in_scantable)
{
	et1.Insert("c", 3);
	et1.Delete("c");
	EXPECT_EQ(true, et1.IsEmpty());
}

TEST_F(Ttab, insert_delete_in_sortedtable)
{
	et2.Insert("c", 3);
	et2.Delete("c");
	EXPECT_EQ(true, et2.IsEmpty());
}

TEST_F(Ttab, insert_delete_in_hashtable)
{
	et3.Insert("c", 3);
	et3.Delete("c");
	EXPECT_EQ(true, et3.IsEmpty());
}

TEST_F(Ttab, delete_search_in_scantable)
{
	EXPECT_EQ(2, t1.Search("b"));
	t1.Delete("b");
	ASSERT_ANY_THROW(t1.Search("b"));
}

TEST_F(Ttab, delete_search_in_sortedtable)
{
	EXPECT_EQ(2, t2.Search("b"));
	t2.Delete("b");
	ASSERT_ANY_THROW(t2.Search("b"));
}

TEST_F(Ttab, delete_search_in_hashtable)
{
	EXPECT_EQ(2, t3.Search("b"));
	t3.Delete("b");
	ASSERT_ANY_THROW(t3.Search("b"));
}

TEST_F(Ttab, cant_insert_elements_with_repeated_key_in_scantable)
{
	et1.Insert("a", 1);
	ASSERT_ANY_THROW(et1.Insert("a", 2););
}

TEST_F(Ttab, cant_insert_elements_with_repeated_key_in_sortedtable)
{
	et2.Insert("a", 1);
	ASSERT_ANY_THROW(et2.Insert("a", 2););
}

TEST_F(Ttab, cant_insert_elements_with_repeated_key_in_hashtable)
{
	et3.Insert("a", 1);
	ASSERT_ANY_THROW(et3.Insert("a", 2););
}



TEST_F(Ttab, correctness_navigation_methods_in_empty_scantable)
{
	ASSERT_ANY_THROW(et1.Reset());
	ASSERT_ANY_THROW(et1.GetNext());
	ASSERT_ANY_THROW(et1.GetCurrent());
	EXPECT_EQ(true,et1.IsTabEnded());
}

TEST_F(Ttab, correctness_navigation_methods_in_empty_sortedtable)
{
	ASSERT_ANY_THROW(et2.Reset());
	ASSERT_ANY_THROW(et2.GetNext());
	ASSERT_ANY_THROW(et2.GetCurrent());
	EXPECT_EQ(true, et2.IsTabEnded());
}

TEST_F(Ttab, correctness_navigation_methods_in_empty_hashtable)
{
	ASSERT_ANY_THROW(et3.Reset());
	//ASSERT_ANY_THROW(et3.GetNext());
	ASSERT_ANY_THROW(et3.GetCurrent());
	EXPECT_EQ(true, et3.IsTabEnded());
}

TEST_F(Ttab, correctness_navigation_methods_in_scantable)
{
	t1.Reset();
	EXPECT_EQ("d", t1.GetCurrent().key);
	EXPECT_EQ(4, *t1.GetCurrent().data);
	
	t1.GetNext();
	EXPECT_EQ("b", t1.GetCurrent().key);
	EXPECT_EQ(2, *t1.GetCurrent().data);

	EXPECT_EQ(true, t1.IsTabEnded());

	t1.GetNext();
	EXPECT_EQ("d", t1.GetCurrent().key);
	EXPECT_EQ(4, *t1.GetCurrent().data);
}

TEST_F(Ttab, correctness_navigation_methods_in_sortedtable)
{	
	t2.Reset();
	EXPECT_EQ("b", t2.GetCurrent().key);
	EXPECT_EQ(2, *t2.GetCurrent().data);

	t2.GetNext();
	EXPECT_EQ("d", t2.GetCurrent().key);
	EXPECT_EQ(4, *t2.GetCurrent().data);

	EXPECT_EQ(true, t2.IsTabEnded());

	t2.GetNext();
	EXPECT_EQ("b", t2.GetCurrent().key);
	EXPECT_EQ(2, *t2.GetCurrent().data);
}

TEST_F(Ttab, correctness_navigation_methods_in_hashdtable)
{
	t2.Reset();
	EXPECT_EQ("b", t2.GetCurrent().key);
	EXPECT_EQ(2, *t2.GetCurrent().data);

	t2.GetNext();
	EXPECT_EQ("d", t2.GetCurrent().key);
	EXPECT_EQ(4, *t2.GetCurrent().data);

	EXPECT_EQ(true, t2.IsTabEnded());

	t2.GetNext();
	EXPECT_EQ("b", t2.GetCurrent().key);
	EXPECT_EQ(2, *t2.GetCurrent().data);
}


