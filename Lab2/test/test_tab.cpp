#include "gtest.h"
#include "Tab.h"
#include "Pol.h"
#include "UnSort_Tab.h"
#include "Sort_Tab.h"
#include "Hash_Tab.h"

TEST(UnSortTab, Create) 
{
	UnSortTab<string, TPolinom> A(20);
	TPolinom a("1+x");
	ASSERT_NO_THROW(A.Insert("1+x", a));

}
class TableTest : public ::testing::Test
{
public:
	HashTab <string, TPolinom> HT;
	SortTab <string, TPolinom> ST;
	UnSortTab <string, TPolinom> UT;

	TableTest() : HT(4), ST(4), UT(4)
	{
		HT.Insert("x", TPolinom("x"));
		ST.Insert("x", TPolinom("x"));
		UT.Insert("x", TPolinom("x"));
		HT.Insert("10+xy", TPolinom("10+xy"));
		ST.Insert("10+xy", TPolinom("10+xy"));
		UT.Insert("10+xy", TPolinom("10+xy"));
		HT.Insert("x^5yz", TPolinom("x^5yz"));
		ST.Insert("x^5yz", TPolinom("x^5yz"));
		UT.Insert("x^5yz", TPolinom("x^5yz"));
	};

};

TEST_F(TableTest, Insert_UnSort_Tab_1)
{
	TPolinom p("xyz");
	ASSERT_NO_THROW(UT.Insert("xyz", p));
}
TEST_F(TableTest, Insert_UnSort_Tab_2)
{
	TPolinom p("x+y");
	ASSERT_NO_THROW(UT.Insert("x+y", p));
}

TEST_F(TableTest, Insert_Sort_Tab_1)
{
	TPolinom p("xyz");
	ASSERT_NO_THROW(ST.Insert("xyz", p));
}
TEST_F(TableTest, Insert_Sort_Tab_2)
{
	TPolinom p("x+y");
	ASSERT_NO_THROW(ST.Insert("x+y", p));
}

TEST_F(TableTest, Insert_Hash_Tab_1)
{
	TPolinom p("xyz");
	ASSERT_NO_THROW(HT.Insert("xyz", p));
}
TEST_F(TableTest, Insert_Hash_Tab_2)
{
	TPolinom p("x+y");
	ASSERT_NO_THROW(UT.Insert("x+y", p));
}

TEST_F(TableTest, Delete_UnSort_Tab_1)
{
	TPolinom p("xyz");
	UT.Insert("xyz", p);
	ASSERT_NO_THROW(UT.Delete("xyz"));
}
TEST_F(TableTest, Delete_UnSort_Tab_2)
{
	TPolinom p("x+z");
	UT.Insert("x+z", p);
	ASSERT_NO_THROW(UT.Delete("x+z"));
}
TEST_F(TableTest, Delete_Sort_Tab_1)
{
	TPolinom p("xyz");
	ST.Insert("xyz", p);
	ASSERT_NO_THROW(ST.Delete("xyz"));
}
TEST_F(TableTest, Delete_Sort_Tab_2)
{
	TPolinom p("x+z");
	ST.Insert("x+z", p);
	ASSERT_NO_THROW(ST.Delete("x+z"));
}

TEST_F(TableTest, Delete_Hash_Tab_1)
{
	TPolinom p("xyz");
	HT.Insert("xyz", p);
	ASSERT_NO_THROW(HT.Delete("xyz"));
}
TEST_F(TableTest, Delete_Hash_Tab_2)
{
	TPolinom p("x+z");
	HT.Insert("x+z", p);
	ASSERT_NO_THROW(HT.Delete("x+z"));
}

TEST_F(TableTest, Search_UnSort_Tab_1)
{
	ASSERT_NO_THROW(UT.Search("x"));
}
TEST_F(TableTest, Search_UnSort_Tab_2)
{
	ASSERT_NO_THROW(UT.Search("10+xy"));
}

TEST_F(TableTest, Search_Sort_Tab_1)
{
	ASSERT_NO_THROW(ST.Search("x"));
}
TEST_F(TableTest, Search_Sort_Tab_2)
{
	ASSERT_NO_THROW(ST.Search("10+xy"));
}

TEST_F(TableTest, Search_Hash_Tab_1)
{
	ASSERT_NO_THROW(HT.Search("x"));
}
TEST_F(TableTest, Search_Hash_Tab_2)
{
	ASSERT_NO_THROW(HT.Search("10+xy"));
}

TEST_F(TableTest, Reset_in_UnSort_Tab)
{
	UT.Reset();
	EXPECT_EQ(UT.GetCurrent(), 0);
}

TEST_F(TableTest, Reset_Sort_Tab)
{
	ST.Reset();
	EXPECT_EQ(ST.GetCurrent(), 0);
}

TEST_F(TableTest, Reset_Hash_Tab)
{
	HT.Reset();
	EXPECT_EQ(HT.GetCurrent(), 0);
}

TEST_F(TableTest, Go_Next_Sort_Tab)
{
	ASSERT_NO_THROW(ST.GoNext());
}

TEST_F(TableTest, Go_Next_UnSort_Tab)
{
	ASSERT_NO_THROW(UT.GoNext());
}

