#include "Queue.h"
#include <gtest.h>

TEST(Queue, can_create_Queue_with_positive_length)
{
	ASSERT_NO_THROW(Queue<int> v(1));
}

TEST(Queue, can_create_Queue_with_zero_size)
{
	ASSERT_NO_THROW(Queue<int> v(0));
}

TEST(Queue, throws_when_create_Queue_with_negative_length)
{
	ASSERT_ANY_THROW(Queue<int> v(-11));
}

TEST(Queue, can_get_size)
{
	Queue<int> v(13);
	EXPECT_EQ(v.GetSize(), 13);
}

TEST(Queue, can_push_and_pop)
{
	Queue<int> A(9);
	int q = 9;
	A.push(q);
	EXPECT_EQ(A.pop(), 9);
}

TEST(Queue, can_pop_with_any_size)
{
	Queue<int> A;
	ASSERT_ANY_THROW(A.pop());
}

TEST(Queue, can_not_pop_out_of_size)
{
	Queue<int> A(3);
	ASSERT_ANY_THROW(A.pop());
}

TEST(Queue, IsFull)
{
	Queue<int>q(1);
	int t = 3;
	q.push(t);
	EXPECT_EQ(q.IsFull(), 1);
}

TEST(Queue, IsEmpty)
{
	Queue<int>q(1);
	int m = 3;
	q.push(m);
	q.pop();
	EXPECT_EQ(q.IsEmpty(), 1);
}

TEST(Queue, IsEmpty)
{
	Queue<int>q(3);
	
	for (int i = 0; i < 3; i++)
		q.push(i);

	for(int i=0;i<3;i++)
		q.pop();

	EXPECT_EQ(q.IsEmpty(), 1);
}

