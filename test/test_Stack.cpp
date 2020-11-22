#include "Stack.h"

#include <gtest.h>


TEST(Stack, IsFull)
{
	Stack<int>q(3);

	for (int i = 0; i < 3; i++)
		q.push(i);

	EXPECT_EQ(q.IsFull(), 1);
}

TEST(Stack, IsEmpty)
{
	Stack<int> stack(3);
	for (int j = 0; j < 3; j++)
		stack.push(j);
	for(int j=0;j<3;j++)
		q.pop();
	EXPECT_EQ(q.IsEmpty(), 1);
}

TEST(Stack, can_get_size)
{
  Stack<int> v(9);

  EXPECT_EQ(v.GetSize(), 9);
}

TEST(Stack, can_push_and_pop)
{
	Stack<int> A(9);
	int q = 9;
	A.push(q);
	EXPECT_EQ(A.pop(), 9);
}

TEST(Stack, can_pop_with_any_size)
{
	Stack<int> A;
	ASSERT_ANY_THROW(A.pop());
}

TEST(Stack, can_not_pop_out_of_size)
{
	Stack<int> A(13);
	ASSERT_ANY_THROW(A.pop());
}


TEST(Stack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(Stack<int> v(9));
}

TEST(Stack, can_create_stack_with_zero_size)
{
	ASSERT_NO_THROW(Stack<int> v(0));
}

TEST(Stack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(Stack<int> v(-9));
}