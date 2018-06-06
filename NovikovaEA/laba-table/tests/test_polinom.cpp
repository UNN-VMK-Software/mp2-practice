#include "polinom.h"
#include <gtest.h>
#include "TablesUnordered.h"
#include "TablesOrdered.h"
#include "TablesHash.h"


TEST(hashtable, Lol)
{
	EXPECT_EQ(1, 1);
}

TEST(monom, create)
{
	monom a;
	EXPECT_EQ(a.abc, 0);
	EXPECT_EQ(a.coeff, 0.0);
}

TEST(monom, create_copy)
{
	monom a(10.0), b(a);
	EXPECT_EQ(b.coeff, 10.0);
	EXPECT_EQ(b.abc, 0);
}

TEST(monom, create_monom)
{
	string a = "10x2y5z";
	monom b(a);
	EXPECT_EQ(b.coeff, 10.0);
	EXPECT_EQ(b.abc, 251);
}

TEST(monom, equate)
{
	monom a(10.0, 1), b(5.0);
	a = b;
	EXPECT_EQ(a.coeff, 5.0);
	EXPECT_EQ(a.abc, 0);
}

TEST(monom, equall)
{
	monom a(10.0, 1), b(5.0);
	EXPECT_NE(a == b, true);
}

TEST(monom, not_equall)
{
	monom a(10.0, 1), b(5.0);
	EXPECT_NE(a, b);
}

TEST (monom, comparsion)
{
	monom a(10.0, 1), b(5.0);
	EXPECT_EQ(a > b, true); 
}

TEST(monom, mult_const)
{
	monom a(3.0, 3);
	monom c;
	double d = 5.0;
	c = a*d;
	EXPECT_EQ(c.coeff, 15.0);
}

TEST(monom, multiplication)
{
	monom a(3.0, 10), b(4.0, 5), c;
	c = a*b;
	EXPECT_EQ(c.coeff, 12.0);
	EXPECT_EQ(c.abc, 15);
}

TEST(polinom, create)
{
	ASSERT_NO_THROW(polinom a);
}

TEST(polinom, createe)
{
	string s = "xyz+5";
	ASSERT_NO_THROW(polinom a(s));
}

TEST(polinom, copy)
{
	polinom a("2xy+5");
	ASSERT_NO_THROW(polinom b(a));
}

TEST(polinom, copyy)
{
	polinom a("2xy+5");
	polinom b(a);
	EXPECT_EQ(b, a);
}

TEST(polinom, can_assign)
{
	polinom a("2xy+10z");
	polinom b("5+xy-z");
	b = a;
	EXPECT_EQ(b, a);
}

TEST(polinom, not_equal)
{
	polinom a("2xy+10z");
	polinom b("5+xy-z");
	EXPECT_EQ(a != b, true);
}

TEST(polinom, equal)
{
	polinom a("2xy+10z");
	polinom b("2xy+10z");
	EXPECT_EQ(a == b, true);
}


TEST(polinom, addition)
{
	polinom a("2xy+10z");
	polinom b("xy-10z");
	polinom c("3xy");
	EXPECT_EQ(c, a + b);
}

TEST(polinom, multconst)
{
	polinom a("2xy+10z");
	double d = 5.0;
	polinom c("10xy+50z");
	EXPECT_EQ(c, a*d);
}

TEST(polinom, multiplicate)
{
	polinom a("2xy+10z");
	polinom b("5z");
	polinom c("10xyz+50z2");
	EXPECT_EQ(c, a*b);
}
// TEsts for Tables
TEST(ScanTable, can_create)
{
	unordtable<string, polinom> A(20);
	polinom a("x+1");
	ASSERT_NO_THROW(A.insert("x+1", a));

}

class Table_Check : public ::testing::Test
{
public:
	hashtable <string, polinom> HashT;
	ordertable <string, polinom> OrdT;
	unordtable <string, polinom> ScanT;

	Table_Check() : HashT(10), OrdT(10), ScanT(10)
	{
		HashT.insert("x+1", polinom("x+1"));
		OrdT.insert("x+1", polinom("x+1"));
		ScanT.insert("x+1", polinom("x+1"));
		HashT.insert("10+xyz", polinom("10+xyz"));
		OrdT.insert("10+xyz", polinom("10+xyz"));
		ScanT.insert("10+xyz", polinom("10+xyz"));
		HashT.insert("x^4", polinom("x^4"));
		OrdT.insert("x^4", polinom("x^4"));
		ScanT.insert("x^4", polinom("x^4"));
	};

};

TEST_F(Table_Check, can_getcurdata_ScanT)
{
	ScanT.reset();
	polinom p("x+1");
	EXPECT_EQ(ScanT.getcurdata(), p);
}

TEST_F(Table_Check, can_search_existed_element_HashT)
{
	EXPECT_EQ(HashT.search("x+1")->data, polinom("x+1"));
}

TEST_F(Table_Check, can_search_existed_element_ScanT)
{
	EXPECT_EQ(ScanT.search("x+1")->data, polinom("x+1"));
}

TEST_F(Table_Check, can_search_existed_element_OrdT)
{
	EXPECT_EQ(OrdT.search("x+1")->data, polinom("x+1"));
}

TEST_F(Table_Check, can_Delete_existed_element_HashT)
{
	HashT.delet("x+1");
	ASSERT_ANY_THROW(HashT.search("x+1"));
}

TEST_F(Table_Check, can_Delete_existed_element_ScanT)
{
	ScanT.delet("x+1");
	ASSERT_ANY_THROW(ScanT.search("x+1"));
}

TEST_F(Table_Check, can_Delete_existed_element_OrdT)
{
	OrdT.delet("x+1");
	ASSERT_ANY_THROW(OrdT.search("x+1"));
}

TEST_F(Table_Check, can_insert_element_HashT)
{
	HashT.insert("1+2x+y", polinom("1+2x+y"));
	EXPECT_EQ(HashT.search("1+2x+y")->data, polinom("1+2x+y"));
}

TEST_F(Table_Check, can_insert_element_ScanT)
{
	ScanT.insert("1+z", polinom("1+z"));
	EXPECT_EQ(ScanT.search("1+z")->data, polinom("1+z"));
}

TEST_F(Table_Check, can_insert_element_OrdT)
{
	OrdT.insert("xyz+z^5", polinom("xyz+z^5"));
	EXPECT_EQ(OrdT.search("xyz+z^5")->data, polinom("xyz+z^5"));
}

TEST_F(Table_Check, can_search_existed_element2_HashT)
{
	EXPECT_EQ(HashT.search("10+xyz")->data, polinom("10+xyz"));
}

TEST_F(Table_Check, can_search_existed_element_ScanT2)
{
	EXPECT_EQ(ScanT.search("10+xyz")->data, polinom("10+xyz"));
}

TEST_F(Table_Check, can_search_existed_element_OrdT2)
{
	EXPECT_EQ(OrdT.search("10+xyz")->data, polinom("10+xyz"));
}

TEST_F(Table_Check, can_search_existed_element_HashT3)
{
	EXPECT_EQ(HashT.search("x^4")->data, polinom("x^4"));
}

TEST_F(Table_Check, can_search_existed_element_ScanT3)
{
	EXPECT_EQ(ScanT.search("x^4")->data, polinom("x^4"));
}

TEST_F(Table_Check, can_search_existed_element_OrdT3)
{
	EXPECT_EQ(OrdT.search("x^4")->data, polinom("x^4"));
}

TEST_F(Table_Check, can_insert_element_HashT2)
{
	HashT.insert("111+z", polinom("111+z"));
	EXPECT_EQ(HashT.search("111+z")->data, polinom("111+z"));
}

TEST_F(Table_Check, can_insert_element_ScanT2)
{
	ScanT.insert("1+32.1x", polinom("1+32.1x"));
	EXPECT_EQ(ScanT.search("1+32.1x")->data, polinom("1+32.1x"));
}

TEST_F(Table_Check, can_insert_element_OrdT2)
{
	OrdT.insert("xyz", polinom("xyz"));
	EXPECT_EQ(OrdT.search("xyz")->data, polinom("xyz"));
}

TEST_F(Table_Check, cannot_Delete_element_HashT)
{
	ASSERT_ANY_THROW(HashT.delet("12"));
}

TEST_F(Table_Check, cannot_Delete_element_ScanT)
{
	ASSERT_ANY_THROW(ScanT.delet("12"));
}

TEST_F(Table_Check, cannot_Delete_element_OrdT)
{
	ASSERT_ANY_THROW(OrdT.delet("12"));
}

TEST_F(Table_Check, cannot_Inset_ex_element_HashT)
{
	ASSERT_ANY_THROW(HashT.insert("x+1", polinom("x+1")));
}

TEST_F(Table_Check, cannot_Inset_ex_element_ScanT)
{
	ASSERT_ANY_THROW(ScanT.insert("x+1", polinom("x+1")));
}

TEST_F(Table_Check,
	cannot_Inset_ex_element_OrdT)
{
	ASSERT_ANY_THROW(OrdT.insert("x+1", polinom("x+1")));
}

TEST_F(Table_Check, cannot_Inset_ex_element_Hash2T)
{
	ASSERT_ANY_THROW(HashT.insert("x^4", polinom("x+1")));
}

TEST_F(Table_Check, cannot_Inset_ex_element_ScanT2)
{
	ASSERT_ANY_THROW(ScanT.insert("x^4", polinom("x+1")));
}

TEST_F(Table_Check, cannot_Inset_ex_element_OrdT2)
{
	ASSERT_ANY_THROW(OrdT.insert("x^4", polinom("x+1")));
}

TEST_F(Table_Check, can_Delete_OrdT)
{
	ASSERT_ANY_THROW(OrdT.delet("100"));
}


