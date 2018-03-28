#include "Polinoms.h"
#include <gtest.h>

//TEST(Node, can_create_node)
//{
//	ASSERT_NO_THROW(TLink<int> a);
//}
//
//TEST(List, can_create_list)
//{
//	ASSERT_NO_THROW(TRingList<int> l);
//}
//
//class EmptyList : public testing::Test
//{
//protected:
//	TRingList <int> l;
//public:
//	EmptyList() {};
//	~EmptyList() {};
//};
//TEST_F(EmptyList, new_list_is_ringed_to_itself)
//{
//	l.Reset();
//	EXPECT_EQ(l.GetNext(), l.current);
//}
//
//TEST_F(EmptyList, can_copy_empty_list)
//{
//	ASSERT_NO_THROW(TRingList<int> l2(l));
//}
//
//TEST_F(EmptyList, empty_list_copy_is_correct)
//{
//	TRingList<int> l2(l);
//	EXPECT_EQ(l2.GetHead(), l2.GetHead()->pNext());
//}
//
//TEST_F(EmptyList, can_assign_two_empty_lists)
//{
//	TRingList <int> l2;
//	ASSERT_NO_THROW(l = l2);
//}
//
//TEST_F(EmptyList, assign_two_empty_lists_is_correct)
//{
//	TRingList <int> l2;
//	l = l2;
//	EXPECT_EQ(l.GetHead(), l.GetHead());
//}
//
//TEST_F(EmptyList, can_insert_to_tail_for_empty_list)
//{
//	l.InsertInEnd(5);
//	EXPECT_EQ(5, l.head()->data);
//	EXPECT_EQ(l.head(), l.head()->pNext);
//}
