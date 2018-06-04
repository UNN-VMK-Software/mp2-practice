//#include "gtest.h"
//#include "list.h"
//
//
//class TList : public testing::Test
//{
//protected:
//	list<int> l1;
//	list<int> l2;
//public:
//	TList() 
//	{		
//		l2.InsertOrd(4);
//		l2.InsertOrd(2);
//	};
//	~TList() {};
//};
//
//TEST_F(TList, can_create_list)
//{
//	ASSERT_NO_THROW(list<int> l);
//}
//
//TEST_F(TList, empty_list_is_correct)
//{
//	EXPECT_EQ(true, l1.IsEnded());
//}
//
//TEST_F(TList, can_copy_empty_list)
//{
//	ASSERT_NO_THROW(list<int> l(l1));
//}
//
//TEST_F(TList, copied_empty_list_is_correct)
//{
//	list<int> l(l1);
//	EXPECT_EQ(true, l.IsEnded());
//	EXPECT_NE(l1.GetCurr(),l.GetCurr());			
//}
//
//TEST_F(TList, can_assign_empty_list)
//{
//	ASSERT_NO_THROW(list<int> l = l1);
//}
//
//TEST_F(TList, assigned_empty_list_is_correct)
//{
//	list<int> l = l1;
//	EXPECT_EQ(true,l.IsEnded());
//	EXPECT_NE(l1.GetCurr(), l.GetCurr());
//}
//
//TEST_F(TList, can_insert_in_ordered_empty_list)
//{	
//	ASSERT_NO_THROW(l1.InsertOrd(1));	
//}
//
//TEST_F(TList, insert_in_ordered_empty_list_is_correct)
//{
//	l1.InsertOrd(1);
//	l1.Reset();
//	EXPECT_EQ(1, l1.GetCurr()->data);
//	EXPECT_EQ(l1.GetCurr(), l1.GetCurr()->next->next);
//}
//
//TEST_F(TList, can_compare_list_with_itself)
//{
//	EXPECT_EQ(true, l1 == l1);
//}
//
//TEST_F(TList, empty_lists_are_equal)
//{
//	list<int> l(l1);
//	EXPECT_EQ(true, l == l1);
//}
//
//
//
//TEST_F(TList, can_copy_filled_list)
//{
//	ASSERT_NO_THROW(list<int> l(l2));
//}
//
//TEST_F(TList, copied_filled_list_is_correct)
//{
//	list<int> l(l2);
//	l.Reset();
//	EXPECT_EQ(4, l.GetCurr()->data);
//	EXPECT_EQ(2, l.GetCurr()->next->data);
//	EXPECT_EQ(l.GetCurr(), l.GetCurr()->next->next->next);
//	l2.Reset();
//	EXPECT_NE(l2.GetCurr()->next->next, l.GetCurr()->next->next);
//}
//
//TEST_F(TList, can_assign_filled_list)
//{
//	ASSERT_NO_THROW(list<int> l = l2);
//}
//
//TEST_F(TList, assigned_filled_list_is_correct)
//{
//	list<int> l = l2;
//	l.Reset();
//	EXPECT_EQ(4, l.GetCurr()->data);
//	EXPECT_EQ(2, l.GetCurr()->next->data);
//	EXPECT_EQ(l.GetCurr(), l.GetCurr()->next->next->next);
//	l2.Reset();
//	EXPECT_NE(l2.GetCurr()->next->next, l.GetCurr()->next->next);
//}
//
//TEST_F(TList, insert_in_the_beginning)
//{
//	l2.InsertOrd(1);
//	l2.Reset();
//	EXPECT_EQ(4, l2.GetCurr()->data);
//	EXPECT_EQ(2, l2.GetCurr()->next->data);
//	EXPECT_EQ(1, l2.GetCurr()->next->next->data);
//	EXPECT_EQ(l2.GetCurr()->next->next->next->next, l2.GetCurr());
//}
//
//TEST_F(TList, insert_in_the_middle)
//{
//	l2.InsertOrd(3);
//	l2.Reset();
//	EXPECT_EQ(4, l2.GetCurr()->data);
//	EXPECT_EQ(3, l2.GetCurr()->next->data);
//	EXPECT_EQ(2, l2.GetCurr()->next->next->data);
//	EXPECT_EQ(l2.GetCurr()->next->next->next->next, l2.GetCurr());
//}
//
//TEST_F(TList, insert_in_the_end)
//{
//	l2.InsertOrd(5);
//	l2.Reset();
//	EXPECT_EQ(5, l2.GetCurr()->data);
//	EXPECT_EQ(4, l2.GetCurr()->next->data);
//	EXPECT_EQ(2, l2.GetCurr()->next->next->data);
//	EXPECT_EQ(l2.GetCurr()->next->next->next->next, l2.GetCurr());
//}
//
//TEST_F(TList, insert)
//{
//	l2.Reset();
//	l2.Insert(l2.GetCurr(), 6);
//	EXPECT_EQ(4, l2.GetCurr()->data);
//	EXPECT_EQ(6, l2.GetCurr()->next->data);
//	EXPECT_EQ(2, l2.GetCurr()->next->next->data);
//	EXPECT_EQ(l2.GetCurr()->next->next->next->next, l2.GetCurr());
//}
//
//TEST_F(TList, insert_to_tail)
//{
//	l2.InsertToTail(3);
//	l2.Reset();
//	EXPECT_EQ(4, l2.GetCurr()->data);
//	EXPECT_EQ(2, l2.GetCurr()->next->data);
//	EXPECT_EQ(3, l2.GetCurr()->next->next->data);
//}
//
//TEST_F(TList, filled_lists_are_equal)
//{
//	list<int> l(l2);
//	EXPECT_EQ(true, l == l2);
//}
//
//TEST_F(TList, empty_and_filled_lists_are_not_equal)
//{
//	EXPECT_EQ(true, l1 !=l2);
//}
//
//TEST_F(TList, lists_with_same_size_are_not_equal)
//{
//	l1.InsertOrd(1);
//	l1.InsertOrd(2);
//	EXPECT_EQ(true, l1 != l2);
//}
