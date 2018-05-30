#include "monom.h"
#include "list.h"
#include "gtest.h"

#include "upor_table.h"
#include "prosm_table.h"
#include "hash_table.h"
#include "polynom.h"


TEST(ScanTable, can_create) // 
{
	ScanTable<string, polynom> A(20);
	polynom a("x+1");
	ASSERT_NO_THROW(A.Insert("x+1", a));

}

class Table_Check : public ::testing::Test
{
public:
	HashTable <string, polynom> HashT;
	OrdTab <string, polynom> OrdT;
	ScanTable <string, polynom> ScanT;

	Table_Check() : HashT(10), OrdT(10), ScanT(10)
	{
		HashT.Insert("x+1", polynom("x+1"));
		OrdT.Insert("x+1", polynom("x+1"));
		ScanT.Insert("x+1", polynom("x+1"));
		HashT.Insert("10+xyz", polynom("10+xyz"));
		OrdT.Insert("10+xyz", polynom("10+xyz"));
		ScanT.Insert("10+xyz", polynom("10+xyz"));
		HashT.Insert("x^4", polynom("x^4"));
		OrdT.Insert("x^4", polynom("x^4"));
		ScanT.Insert("x^4", polynom("x^4"));
	};

};


TEST_F(Table_Check, can_GetCur_ScanT)
{
	ScanT.Reset();
	polynom p("x+1");
	EXPECT_EQ(ScanT.GetCur(), p);
}

TEST_F(Table_Check, can_gonext_OrdT)
{
	ASSERT_NO_THROW(OrdT.gonext());
}

TEST_F(Table_Check, can_gonext_HashT)
{
	ASSERT_NO_THROW(HashT.gonext());
}

TEST_F(Table_Check, can_get_next_ScanT)
{
	ASSERT_NO_THROW(ScanT.gonext());
}

TEST_F(Table_Check, can_Search_existed_element_HashT)
{
	EXPECT_EQ(HashT.Search("x+1")->Data, polynom("x+1"));
}

TEST_F(Table_Check, can_Search_existed_element_ScanT)
{
	EXPECT_EQ(ScanT.Search("x+1")->Data, polynom("x+1"));
}

TEST_F(Table_Check, can_Search_existed_element_OrdT)
{
	EXPECT_EQ(OrdT.Search("x+1")->Data, polynom("x+1"));
}

TEST_F(Table_Check, can_Delete_existed_element_HashT)
{
	HashT.Delete("x+1");
	ASSERT_ANY_THROW(HashT.Search("x+1"));
}

TEST_F(Table_Check, can_Delete_existed_element_ScanT)
{
	ScanT.Delete("x+1");
	ASSERT_ANY_THROW(ScanT.Search("x+1"));
}

TEST_F(Table_Check, can_Delete_existed_element_OrdT)
{
	OrdT.Delete("x+1");
	ASSERT_ANY_THROW(OrdT.Search("x+1"));
}

TEST_F(Table_Check, can_Insert_element_HashT)
{
	HashT.Insert("1+2x+y", polynom("1+2x+y"));
	EXPECT_EQ(HashT.Search("1+2x+y")->Data, polynom("1+2x+y"));
}

TEST_F(Table_Check, can_Insert_element_ScanT)
{
	ScanT.Insert("1+z", polynom("1+z"));
	EXPECT_EQ(ScanT.Search("1+z")->Data, polynom("1+z"));
}

TEST_F(Table_Check, can_Insert_element_OrdT)
{
	OrdT.Insert("xyz+z^5", polynom("xyz+z^5"));
	EXPECT_EQ(OrdT.Search("xyz+z^5")->Data, polynom("xyz+z^5"));
}

TEST_F(Table_Check, can_Search_existed_element2_HashT)
{
	EXPECT_EQ(HashT.Search("10+xyz")->Data, polynom("10+xyz"));
}

TEST_F(Table_Check, can_Search_existed_element_ScanT2)
{
	EXPECT_EQ(ScanT.Search("10+xyz")->Data, polynom("10+xyz"));
}

TEST_F(Table_Check, can_Search_existed_element_OrdT2)
{
	EXPECT_EQ(OrdT.Search("10+xyz")->Data, polynom("10+xyz"));
}

TEST_F(Table_Check, can_Search_existed_element_HashT3)
{
	EXPECT_EQ(HashT.Search("x^4")->Data, polynom("x^4"));
}

TEST_F(Table_Check, can_Search_existed_element_ScanT3)
{
	EXPECT_EQ(ScanT.Search("x^4")->Data, polynom("x^4"));
}

TEST_F(Table_Check, can_Search_existed_element_OrdT3)
{
	EXPECT_EQ(OrdT.Search("x^4")->Data, polynom("x^4"));
}

TEST_F(Table_Check, can_Insert_element_HashT2)
{
	HashT.Insert("111+z", polynom("111+z"));
	EXPECT_EQ(HashT.Search("111+z")->Data, polynom("111+z"));
}

TEST_F(Table_Check, can_Insert_element_ScanT2)
{
	ScanT.Insert("1+32.1x", polynom("1+32.1x"));
	EXPECT_EQ(ScanT.Search("1+32.1x")->Data, polynom("1+32.1x"));
}

TEST_F(Table_Check, can_Insert_element_OrdT2)
{
	OrdT.Insert("xyz", polynom("xyz"));
	EXPECT_EQ(OrdT.Search("xyz")->Data, polynom("xyz"));
}

TEST_F(Table_Check, cannot_Delete_element_HashT)
{
	ASSERT_ANY_THROW(HashT.Delete("12"));
}

TEST_F(Table_Check, cannot_Delete_element_ScanT)
{
	ASSERT_ANY_THROW(ScanT.Delete("12"));
}

TEST_F(Table_Check, cannot_Delete_element_OrdT)
{
	ASSERT_ANY_THROW(OrdT.Delete("12"));
}

TEST_F(Table_Check, cannot_Inset_ex_element_HashT)
{
	ASSERT_ANY_THROW(HashT.Insert("x+1", polynom("x+1")));
}

TEST_F(Table_Check, cannot_Inset_ex_element_ScanT)
{
	ASSERT_ANY_THROW(ScanT.Insert("x+1", polynom("x+1")));
}

TEST_F(Table_Check, cannot_Inset_ex_element_OrdT)
{
	ASSERT_ANY_THROW(OrdT.Insert("x+1", polynom("x+1")));
}

TEST_F(Table_Check, cannot_Inset_ex_element_Hash2T)
{
	ASSERT_ANY_THROW(HashT.Insert("x^4", polynom("x+1")));
}

TEST_F(Table_Check, cannot_Inset_ex_element_ScanT2)
{
	ASSERT_ANY_THROW(ScanT.Insert("x^4", polynom("x+1")));
}

TEST_F(Table_Check, cannot_Inset_ex_element_OrdT2)
{
	ASSERT_ANY_THROW(OrdT.Insert("x^4", polynom("x+1")));
}

TEST_F(Table_Check, can_Delete_OrdT)
{
	ASSERT_ANY_THROW(OrdT.Delete("100"));
}








