#include "RingList.h"
#include "Polinoms.h"
#include "TMonom.h"
#include "TLink.h"
#include <gtest.h>
#include <ScanTable.h>
#include <SortedTable.h>
#include <HashTable.h>


TEST(HashTable, can_create_hash_table)
{
	ASSERT_NO_THROW(HashTable<TPolinom> T);
}

//TEST(SortedTable, can_create_sorted_table)
//{
//	ASSERT_NO_THROW(SortedTable<std::string, int> T(20));
//}

//TEST(ScanTable, can_create_scan_table)
//{
//	ASSERT_NO_THROW(ScanTable<std::string, int> t1);
//}


class ThreeElemsTable : public testing::Test
{
protected:
	ScanTable<std::string, TPolinom> t1;
	SortedTable<std::string, TPolinom> t2;
	HashTable<TPolinom> t3;
public:
	ThreeElemsTable()
	{
		std::string s1 = "x+y";
		std::string s2 = "2x+y";
		std::string s3 = "x^2y";

		t1.Insert(s1, new TPolinom(s1));
		t1.Insert(s2, new TPolinom(s2));
		t1.Insert(s3, new TPolinom(s3));

		t2.Insert(s1, new TPolinom(s1));
		t2.Insert(s2, new TPolinom(s2));
		t2.Insert(s3, new TPolinom(s3));

		t3.Insert(s1, new TPolinom(s1));
		t3.Insert(s2, new TPolinom(s2));
		t3.Insert(s3, new TPolinom(s3));
	}
	~ThreeElemsTable() {};
};

TEST_F(ThreeElemsTable, can_find_existing_element)
{
	std::string key = "x+y";
	EXPECT_EQ(true, nullptr != t1.Search(key));
	EXPECT_EQ(true, nullptr != t2.Search(key));
	EXPECT_EQ(true, nullptr != t3.Search(key));
}

TEST_F(ThreeElemsTable, can_not_find_not_existing_element)
{
	std::string key = "3x+y";
	EXPECT_EQ(true, nullptr == t1.Search(key));
	EXPECT_EQ(true, nullptr == t2.Search(key));
	EXPECT_EQ(true, nullptr == t3.Search(key));
}

TEST_F(ThreeElemsTable, correctly_finds_existing_element)
{
	std::string key = "x+y";
	TPolinom res(key);
	EXPECT_EQ(res, *(t1.Search(key)));
	EXPECT_EQ(res, *(t2.Search(key)));
	EXPECT_EQ(res, *(t3.Search(key)));
}

TEST_F(ThreeElemsTable, can_delete_existing_element)
{
	std::string key = "x+y";
	ASSERT_NO_THROW(t1.Delete(key));
	ASSERT_NO_THROW(t2.Delete(key));	
	ASSERT_NO_THROW(t3.Delete(key));
}

TEST_F(ThreeElemsTable, can_not_delete_not_existing_element)
{
	std::string key = "x^3+y";
	ASSERT_ANY_THROW(t3.Delete(key));
}

TEST_F(ThreeElemsTable, can_delete_deleted_element)
{
	std::string key = "x^3+y";
	TPolinom *res = new TPolinom(key);
	t3.Insert(key, res);
	t3.Delete(key);
	ASSERT_ANY_THROW(t3.Delete(key));
}

TEST_F(ThreeElemsTable, correctly_deletes_existing_element)
{
	std::string key = "x^2y";
	ASSERT_NO_THROW(t1.Delete(key));
	ASSERT_NO_THROW(t2.Delete(key));
	ASSERT_NO_THROW(t3.Delete(key));
	EXPECT_EQ(true, nullptr == t1.Search(key));
	EXPECT_EQ(true, nullptr == t2.Search(key));
	EXPECT_EQ(true, nullptr == t3.Search(key));
}



TEST(TPolinom, can_create_polinom)
{
	ASSERT_NO_THROW(TPolinom a(""));
}

TEST(TPolinom, two_empty_polinoms_are_equal)
{
	TPolinom b("");
	TPolinom a("");
	EXPECT_EQ(a, b);
}

TEST(TPolinom, can_build_polinom)
{
	ASSERT_NO_THROW(TPolinom a("10x^2"));
}

TEST(TPolinom, can_create_polinom_after_existing)
{
	TPolinom a("10x^2");
	ASSERT_NO_THROW(TPolinom b(a));
}

TEST(TPolinom, can_create_polinom_with_equal_monoms)
{
	TPolinom a("10x^2+3x^2");
	TPolinom b("13x^2");
	ASSERT_NO_THROW(a, b);
}

TEST(TPolinom, can_sum_two_polinoms_1)
{
	TPolinom a("10x^2");
	TPolinom b("12y^2");
	ASSERT_NO_THROW(a + b);
}

TEST(TPolinom, can_sum_two_polinoms_2)
{
	TPolinom a("10x^2+40y-z");
	TPolinom b("12y^2-30xy^4+12xy^3");
	ASSERT_NO_THROW(a + b);
}

TEST(TPolinom, sum_of_two_polinoms_is_correct_1)
{
	TPolinom a("10x^2");
	TPolinom b("12y^2");
	TPolinom c("10x^2+12y^2");
	EXPECT_EQ(c, a + b);
}

TEST(TPolinom, sum_of_two_polinoms_is_correct_2)
{
	TPolinom a("10x^2+40y-z");
	TPolinom b("12y^2-30xy^4+12xy^3");
	TPolinom c("10x^2-30xy^4+12xy^3+12y^2+40y-z");
	EXPECT_EQ(c, a + b);
}

TEST(TPolinom, can_substract_two_polinoms)
{
	TPolinom a("x+1");
	TPolinom b("x-1");
	ASSERT_NO_THROW(a + b);
}

TEST(TPolinom, substract_of_two_polinoms_is_correct_1)
{
	TPolinom a("x+1");
	TPolinom b("x-1");
	TPolinom c("-2");
	EXPECT_EQ(c, b - a);
}

TEST(TPolinom, substract_of_two_polinoms_is_correct_2)
{
	TPolinom a("x+1");
	TPolinom b("x-1");
	TPolinom c("2");
	EXPECT_EQ(c, a - b);
}

TEST(TPolinom, can_multiple_two_polinoms_1)
{
	TPolinom a("10x^2");
	TPolinom b("12y^2");
	ASSERT_NO_THROW(a * b);
}
TEST(TPolinom, can_multiple_two_polinoms_2)
{
	TPolinom a("10x^2");
	TPolinom b("12y^2");
	ASSERT_NO_THROW(a * b);
}

TEST(TPolinom, multiple_of_two_polinoms_is_correct_1)
{
	TPolinom a("10x^2");
	TPolinom b("12y^2");
	TPolinom c("120x^2y^2");
	EXPECT_EQ(c, a * b);
}

TEST(TPolinom, can_not_multiple_having_result_power_over_10)
{
	TPolinom a("10z^2");
	TPolinom b("z^8");
	ASSERT_ANY_THROW(a * b);
}

TEST(TPolinom, multiple_of_two_polinoms_is_correct_3)
{
	TPolinom a("x+1");
	TPolinom b("x-1");
	TPolinom c("x^2-1");
	EXPECT_EQ(c, a * b);
}

TEST(TPolinom, multiple_of_two_polinoms_is_correct_4)
{
	TPolinom a("x+1");
	TPolinom c("x^2+2x+1");
	EXPECT_EQ(c, a * a);
}

TEST(TPolinom, multiple_of_two_polinoms_is_correct_2)
{
	TPolinom a("10x^2-50x+3z-5");
	TPolinom b("12y^2+31xyz-30x");
	TPolinom c("310x^3yz-300x^3+120x^2y^2-1550x^2yz+1500x^2-600xy^2+93xyz^2-155xyz-90xz+150x+36y^2z-60y^2");
	EXPECT_EQ(c, a * b);
}

TEST(TPolinom, can_multiple_and_collect_equal_powers)
{
	TPolinom a("xy^2+4x");
	TPolinom b("y^2+20");
	TPolinom c("xy^4+4xy^2+20xy^2+80x");
	TPolinom d("xy^4+24xy^2+80x");
	EXPECT_EQ(c, a * b);
	EXPECT_EQ(c, d);
}

TEST(TPolinom, can_multiple_polinom_on_double_1)
{
	TPolinom a("10x^2");
	double b = 21.5;
	ASSERT_NO_THROW(a * b);
}

TEST(TPolinom, can_multiple_polinom_on_double_2)
{
	TPolinom a("10x^2+40xy-2z");
	double b = 21.5;
	ASSERT_NO_THROW(a * b);
}

TEST(TPolinom, multiple_polinom_on_double_is_correct_1)
{
	TPolinom a("10x^2");
	double b = 21.5;
	TPolinom c("215x^2");
	EXPECT_EQ(c, a * b);
}
TEST(TPolinom, multiple_polinom_on_double_is_correct_2)
{
	TPolinom a("10x^2-20y+z");
	double b = 3.5;
	TPolinom c("35x^2-70y+3.5z");
	EXPECT_EQ(c, a * b);
}

TEST(TMonom, can_create_node)
{
	ASSERT_NO_THROW(Tmonom a);
}

TEST(TRingList, can_create_list)
{
	ASSERT_NO_THROW(TRingList<int> l);
}

class EmptyList : public testing::Test
{
protected:
	TRingList<int> l;
public:
	EmptyList() {};
	~EmptyList() {};
};

TEST_F(EmptyList, new_list_is_ringed_to_itself)
{
	l.Reset();
	EXPECT_EQ(l.GetCurrent(), l.GetNext());
}


TEST_F(EmptyList, can_copy_empty_list)
{
	ASSERT_NO_THROW(TRingList<int> l2(l));
}

TEST_F(EmptyList, empty_list_copy_is_correct)
{
	TRingList<int> l2(l);
	l2.Reset();
	EXPECT_EQ(l.GetCurrent(), l.GetNext());
}


TEST_F(EmptyList, two_empty_lists_are_eq)
{
	TRingList<int> l2;
	EXPECT_EQ(true, l == l2);
}

TEST_F(EmptyList, can_assign_two_empty_lists)
{
	TRingList<int> l2;
	ASSERT_NO_THROW(l = l2);
}

TEST_F(EmptyList, assign_two_empty_lists_is_correct)
{
	TRingList<int> l2;
	l = l2;
	EXPECT_EQ(l.GetCurrent(), l.GetNext());
}


TEST_F(EmptyList, can_insert_to_tail_for_empty_list)
{
	l.InsertInEnd(5);
	l.Reset();
	EXPECT_EQ(5, l.GetCurrent()->data);
	EXPECT_EQ(l.GetCurrent(), l.GetCurrent()->pNext->pNext);
}


TEST_F(EmptyList, can_search_for_empty_list)
{
	ASSERT_NO_THROW(l.Search(5));
}

TEST_F(EmptyList, search_for_empty_list_is_correct)
{
	TLink<int>* p = l.Search(6);
	EXPECT_EQ(NULL, p);
}

TEST_F(EmptyList, can_clean_empty_list)
{
	ASSERT_NO_THROW(l.Clean());
}

TEST_F(EmptyList, can_not_delete_from_empty_list)
{
	ASSERT_ANY_THROW(l.Delete(5));
}

TEST_F(EmptyList, delete_from_empty_list_is_correct)
{
	l.InsertInEnd(5);
	l.Delete(5);
	l.Reset();
	EXPECT_EQ(l.GetCurrent(), l.GetCurrent()->pNext);
}

TEST_F(EmptyList, ca_not_delete_not_a_member_of_list)
{
	l.InsertInEnd(5);
	ASSERT_ANY_THROW(l.Delete(6));
}

TEST_F(EmptyList, clean_empty_list_is_correct)
{
	l.Clean();
	l.Reset();
	EXPECT_EQ(l.GetCurrent(), l.GetCurrent()->pNext);
}




//------------------------------------------------------------------------------------------

class ThreeNodesList : public testing::Test
{
protected:
	TRingList<int> l;
public:
	ThreeNodesList()
	{
		l.InsertInEnd(1);
		l.InsertInEnd(2);
		l.InsertInEnd(3);
	}
	~ThreeNodesList() {};
};

TEST_F(ThreeNodesList, three_nodes_list_is_correct)
{
	l.Reset();
	EXPECT_EQ(1, l.GetCurrent()->data);
	EXPECT_EQ(2, l.GetCurrent()->pNext->data);
	EXPECT_EQ(3, l.GetCurrent()->pNext->pNext->data);
	EXPECT_EQ(l.GetCurrent()->pNext->pNext->pNext, l.GetCurrent()->pNext->pNext->pNext->pNext->pNext->pNext->pNext);
}


TEST_F(ThreeNodesList, can_copy_not_empty_list)
{
	ASSERT_NO_THROW(TRingList<int> l2(l));
}

TEST_F(ThreeNodesList, copy_of_not_empty_list_is_correct)
{
	TRingList<int> l2(l);
	l2.Reset();
	// так написано, т.к. предполагаем, что == еще не реализовано или не работает
	EXPECT_EQ(1, l2.GetCurrent()->data);
	EXPECT_EQ(2, l2.GetCurrent()->pNext->data);
	EXPECT_EQ(3, l2.GetCurrent()->pNext->pNext->data);
	EXPECT_EQ(l2.GetCurrent()->pNext->pNext->pNext, l2.GetCurrent()->pNext->pNext->pNext->pNext->pNext->pNext->pNext);
}




TEST_F(ThreeNodesList, can_insert_in_end_for_not_empty_list)
{
	l.InsertInEnd(5);
	l.Reset();
	EXPECT_EQ(5, l.GetCurrent()->pNext->pNext->pNext->data);
	EXPECT_EQ(l.GetCurrent()->pNext->pNext->pNext->pNext, l.GetCurrent()->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext);
}




TEST_F(ThreeNodesList, can_search_for_not_empty_list)
{
	ASSERT_NO_THROW(l.Search(3));
}

TEST_F(ThreeNodesList, search_for_not_empty_list_is_correct)
{
	l.Reset();
	TLink<int> * p = l.Search(3);
	TLink<int> * ptrue = l.GetCurrent()->pNext->pNext;
	EXPECT_EQ(ptrue, p);
}

TEST_F(ThreeNodesList, can_search_not_a_member_for_not_empty_list)
{
	ASSERT_NO_THROW(l.Search(5));
}

TEST_F(ThreeNodesList, search_not_a_member_for_not_empty_list_is_correct)
{
	TLink<int> * p = l.Search(7);
	EXPECT_EQ(nullptr, p);
}

TEST_F(ThreeNodesList, can_clean_not_empty_list)
{
	ASSERT_NO_THROW(l.Clean());
}

TEST_F(ThreeNodesList, clean_not_empty_list_is_correct)
{
	l.Clean();
	l.Reset();
	EXPECT_EQ(l.GetCurrent(), l.GetCurrent()->pNext);
}


TEST_F(ThreeNodesList, can_assign_two_not_empty_lists)
{
	TRingList<int> l2;
	l2.InsertInEnd(22);
	l2.InsertInEnd(33);
	ASSERT_NO_THROW(l = l2);
}

TEST_F(ThreeNodesList, can_assign_two_not_empty_lists_of_eq_size)
{
	TRingList<int> l2;
	l2.InsertInEnd(11);
	l2.InsertInEnd(22);
	l2.InsertInEnd(33);
	l = l2;
	l.Reset();
	EXPECT_EQ(11, l.GetCurrent()->data);
	EXPECT_EQ(22, l.GetCurrent()->pNext->data);
	EXPECT_EQ(33, l.GetCurrent()->pNext->pNext->data);
	EXPECT_EQ(l.GetCurrent()->pNext->pNext->pNext, l.GetCurrent()->pNext->pNext->pNext->pNext->pNext->pNext->pNext);
}

TEST_F(ThreeNodesList, compare_two_eq_lists_is_correct)
{
	TRingList<int> l2(l);
	EXPECT_EQ(true, l == l2);
}


class TwoListsTest : public testing::Test
{
protected:
	TRingList<int> l;
	TRingList<int> l2;
	TRingList<int> z;

public:
	TwoListsTest()
	{
		l.InsertInEnd(1);
		l.InsertInEnd(2);
		l.InsertInEnd(3);
		l2.InsertInEnd(11);
		l2.InsertInEnd(22);
	}

	~TwoListsTest() {}
};

TEST_F(TwoListsTest, can_assign_two_not_empty_lists_of_not_eq_size)
{
	ASSERT_NO_THROW(l = l2);
}

TEST_F(TwoListsTest, assign_two_not_empty_lists_of_not_eq_size_is_correct)
{
	l = l2;
	l.Reset();
	EXPECT_EQ(11, l.GetCurrent()->data);
	EXPECT_EQ(22, l.GetCurrent()->pNext->data);
	EXPECT_EQ(l.GetCurrent()->pNext->pNext, l.GetCurrent()->pNext->pNext->pNext->pNext->pNext);
}

TEST_F(TwoListsTest, assign_list_to_empty_is_correct)
{
	l = z;
	l.Reset();
	EXPECT_EQ(l.GetCurrent()->pNext, l.GetCurrent());
}

TEST_F(TwoListsTest, assign_empty_list_to_not_empty_is_correct)
{
	z = l;
	EXPECT_EQ(l, z);
}

TEST_F(TwoListsTest, can_compare_two_not_empty_lists)
{
	ASSERT_NO_THROW(l == l2);
}

TEST_F(TwoListsTest, compare_two_not_eq_lists_of_eq_size)
{
	l2.Insert(3);
	EXPECT_EQ(false, l == l2);
}

TEST_F(TwoListsTest, compare_two_not_eq_lists_with_bigger_list_left)
{
	EXPECT_EQ(false, l == l2);
}

TEST_F(TwoListsTest, compare_two_not_eq_lists_with_bigger_list_right)
{
	EXPECT_EQ(false, l2 == l);
}

TEST_F(TwoListsTest, compare_list_with_empty_list_left)
{
	EXPECT_EQ(false, z == l2);
}

TEST_F(TwoListsTest, compare_list_with_empty_list_right)
{
	EXPECT_EQ(false, l2 == z);
}





