#include "gtest.h"
#include "list.h"

TEST(list, can_create_list)
{
	ASSERT_NO_THROW(list<int> l);
}

class TList : public testing::Test
{
protected:
	list<int> l1;
	list<int> l2;
public:
	TList() 
	{
		l2.InsertOrd(1);
		l2.InsertOrd(4);
		l2.InsertOrd(2);
	};
	~TList() {};
};


