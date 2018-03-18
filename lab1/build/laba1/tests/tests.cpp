#include "Polinoms.h"
#include <gtest.h>

TEST(Node, can_create_node)
{
	ASSERT_NO_THROW(TLink<int> a);
}

TEST(List, can_create_list)
{
	ASSERT_NO_THROW(TRingList<int> l);
}

class EmptyList : public testing::Test
{
protected:
	TRingList <int> l;
public:
	EmptyList() {};
	~EmptyList() {};
};
TEST_F(EmptyList, new_list_is_ringed_to_itself)
{
	l.Reset();
	EXPECT_EQ(l.GetNext(), l.current);
}
