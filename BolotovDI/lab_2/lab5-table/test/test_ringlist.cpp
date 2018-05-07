#include "TRingList.h"
#include "gtest.h"


TEST(TMonom, can_create_link)
{
	ASSERT_NO_THROW(TMonom a);
}

TEST(TRingList, can_create_list)
{
	ASSERT_NO_THROW(TRingList<int> tmp);
}

class EmptyList : public testing::Test
{
protected:
	TRingList<int> l;
public:
	EmptyList() {};
	~EmptyList() {};
};

TEST_F(EmptyList, new_list_is_empty)
{
	EXPECT_EQ(NULL, l.GetLink()->data);
}

TEST_F(EmptyList, can_copy_empty_list)
{
	ASSERT_NO_THROW(TRingList<int> l2(l));
}

TEST_F(EmptyList, empty_list_copy_is_correct)
{
	TRingList<int> l2(l);
	EXPECT_EQ(NULL, l2.GetLink()->data);
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
	EXPECT_EQ(NULL, l.GetLink()->data);
}

TEST_F(EmptyList, can_clean_empty_list)
{
	ASSERT_NO_THROW(l.Clean());
}

TEST_F(EmptyList, clean_empty_list_is_correct)
{
	l.Clean();
	EXPECT_EQ(NULL, l.GetLink()->data);
}

TEST_F(EmptyList, can_get_current_from_empty_list)
{
	ASSERT_NO_THROW(l.GetLink());
}

TEST_F(EmptyList, can_reset_empty_list)
{
	ASSERT_NO_THROW(l.Reset());
}

TEST_F(EmptyList, reset_empty_list_is_correct)
{
	l.Reset();
	EXPECT_EQ(NULL, l.GetLink()->data);
}

TEST_F(EmptyList, is_end_is_correct)
{
	EXPECT_EQ(true, l.IsEnded());
}

class Filledlist : public testing::Test
{
protected:
	TRingList<int> l;
public:
	Filledlist()
	{
		for (int i = 0; i<3; i++)
			l.Insert(i);
	};
	~Filledlist() {};
};

TEST_F(Filledlist, can_copy_filled_list)
{
	ASSERT_NO_THROW(TRingList<int> A(l));
}

TEST_F(Filledlist, copied_filled_list_is_correct)
{
	TRingList<int> A(l);
	A.Reset();
	EXPECT_EQ(2, A.GetLink()->data);
	A.Next();
	EXPECT_EQ(1, A.GetLink()->data);
	A.Next();
	EXPECT_EQ(0, A.GetLink()->data);
}

TEST_F(Filledlist, can_assign_filled_list)
{
	ASSERT_NO_THROW(TRingList<int> A = l);
}

TEST_F(Filledlist, assigned_filled_list_is_correct)
{
	TRingList<int> A = l;
	A.Reset();
	EXPECT_EQ(2, A.GetLink()->data);
	A.Next();
	EXPECT_EQ(1, A.GetLink()->data);
	A.Next();
	EXPECT_EQ(0, A.GetLink()->data);
}