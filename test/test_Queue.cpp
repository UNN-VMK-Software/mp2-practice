#include "Queue.h"

#include <gtest.h>

TEST(Queue, can_create_Queue_with_positive_length)
{
	ASSERT_NO_THROW(Queue<int> v(5));
}

TEST(Queue, can_create_Queue_with_zero_size)
{
	ASSERT_NO_THROW(Queue<int> v(0));
}

TEST(Queue, throws_when_create_Queue_with_negative_length)
{
	ASSERT_ANY_THROW(Queue<int> v(-5));
}

TEST(Queue, IsFull)
{
	Queue<int>q(1);
	int m = 2;
	q.push(m);
	EXPECT_EQ(q.IsFull(), 1);
}

TEST(Queue, IsEmpty)
{
	Queue<int>q(1);
	int m = 2;
	q.push(m);
	q.pop();
	EXPECT_EQ(q.IsEmpty(), 1);
}

TEST(Queue, can_create_copied_Queue)
{
	Queue<int> v(10);

	ASSERT_NO_THROW(Queue<int> v1(v));
}

TEST(Queue, copied_Queue_has_its_own_memory)
{
	Queue<int>A(5);
	Queue<int>B(A);
	EXPECT_NE(A.GetMemory(), B.GetMemory());
}

TEST(Queue, can_get_size)
{
	Queue<int> v(4);

	EXPECT_EQ(4, v.GetSize());
}

TEST(Queue, can_get_start_index)
{
	Queue<int> v(4);

	EXPECT_EQ(0, v.GetFirst());
}

TEST(Queue, pushAndpop)
{
	Queue<int>A(5);
	int a[6];
	for (int i = 0; i < 6; i++)
	{
		a[i] = 4 * i;
	}
	for (int i = A.GetFirst(); i < A.GetSize(); i++)
	{
		A.push(a[i]);
	}
	EXPECT_EQ(A.pop(), 0);
}

