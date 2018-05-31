#include <gtest.h>
#include "polinom.h"
#include "monom.h"
#include "TablesHash.h"
#include "TablesUnord.h"
#include "TablesOrdered.h"
//*****************POLINOMS_TEST*************************************************
TEST(list, insert_to_end) // вставка в конец 
{
	Monom a(12, 14);
	Monom b(14, 43);
	list<Monom> l;
	l.Insert_to_tail(a);
	l.Insert_to_tail(b);
	l.reset();
	Monom res(l.getcurrentdate());
	EXPECT_EQ(res, a);

}

TEST(list, can_create_list) // может создать лист 
{
	EXPECT_NO_THROW(list<Monom> l);
}

TEST(list, delete_last_not_empty_list) // Удаление не пустого листа 
{
	Monom a(12, 14);
	Monom b(14, 43);
	list<Monom> l;
	l.Insert_to_tail(a);
	l.Insert_to_tail(b);
	l.clear();
	EXPECT_EQ(l.IsEmpty(), 1);
}

TEST(list, can_check_is_empty) // проверка на пустоту не пустого листа 
{
	Monom a(12, 14);
	Monom b(14, 43);
	list<Monom> l;
	l.Insert_to_tail(a);
	l.Insert_to_tail(b);
	EXPECT_EQ(0, l.IsEmpty());
}

TEST(list, can_check_is_empty_if_empty) // проверка на пустоту пустого листа 
{
	list<Monom> l;
	EXPECT_EQ(1, l.IsEmpty());
}


TEST(list, operator_ravno_for_list) // проверка оператора = 
{
	Monom a(12, 14);
	Monom b(14, 43);
	list<Monom> l;
	l.Insert_to_tail(a);
	l.Insert_to_tail(b);
	list<Monom> z = l;
	EXPECT_EQ(z, l);
}

TEST(list, operator_ravno_for_list2)
{
	Monom a(12, 14);
	Monom b(14, 43);
	list<Monom> l;
	l.Insert_to_tail(a);
	l.Insert_to_tail(b);
	list<Monom> z = l;
	if (l == z)
		EXPECT_EQ(l, z);
}

TEST(list, operator_ravno_for_list3)
{
	Monom a(12, 14);
	Monom b(14, 43);
	Monom c(11, 123);
	Monom d(12, 1232);
	list<Monom> l;
	l.Insert_to_tail(a);
	l.Insert_to_tail(b);
	l.Insert_to_tail(c);
	l.Insert_to_tail(d);
	list<Monom> z = l;
	if (l == z)
		EXPECT_EQ(l, z);
}
/*****************************************************/
//dellcurent 
TEST(list, Dellcurent_first)
{
	Monom a(12, 14);
	Monom b(14, 43);
	Monom c(11, 123);
	Monom d(12, 1232);
	list<Monom> l;
	l.Insert_to_tail(a);
	l.Insert_to_tail(b);
	l.Insert_to_tail(c);
	l.Insert_to_tail(d);
	l.reset();
	l.Dellcurrent();
	EXPECT_EQ(l.getcurrentdate(), b);
}

TEST(list, Dellcurent_last)
{
	Monom a(12, 14);
	Monom b(14, 43);
	Monom c(11, 123);
	Monom d(12, 1232);
	list<Monom> l;
	l.Insert_to_tail(a);
	l.Insert_to_tail(b);
	l.Insert_to_tail(c);
	l.Insert_to_tail(d);
	l.getnext();
	l.Dellcurrent();
	EXPECT_EQ(l.getcurrentdate(), c);
}

TEST(list, Dellcurent_middle)
{
	Monom a(12, 14);
	Monom b(14, 43);
	Monom c(11, 123);
	Monom d(12, 1232);
	list<Monom> l;
	l.Insert_to_tail(a);
	l.Insert_to_tail(b);
	l.Insert_to_tail(c);
	l.Insert_to_tail(d);
	l.Dellcurrent();
	EXPECT_EQ(l.getcurrentdate(), b);
}

TEST(list, Dellcurent_first_must_empty)
{
	Monom a(12, 14);
	list<Monom> l;
	l.Insert_to_tail(a);
	l.reset();
	l.Dellcurrent();
	EXPECT_EQ(l.IsEmpty(), 1);
}

TEST(list, can_get_currnextdata)
{
	Monom a(12, 14);
	Monom b(14, 43);
	Monom c(11, 123);
	Monom d(12, 1232);
	list<Monom> l;
	l.Insert_to_tail(a);
	l.Insert_to_tail(b);
	l.Insert_to_tail(c);
	l.Insert_to_tail(d);
	EXPECT_EQ(l.getnextcurrentdate(), d);

}

TEST(list, can_get_currdata)
{
	Monom a(12, 14);
	Monom b(14, 43);
	Monom c(11, 123);
	Monom d(12, 1232);
	list<Monom> l;
	l.Insert_to_tail(a);
	l.Insert_to_tail(b);
	l.Insert_to_tail(c);
	l.Insert_to_tail(d);
	EXPECT_EQ(l.getcurrentdate(), c);

}

TEST(list, can_getnext_node)
{
	Monom a(12, 14);
	Monom b(14, 43);
	Monom c(11, 123);
	Monom d(12, 1232);
	list<Monom> l;
	l.Insert_to_tail(a);
	l.Insert_to_tail(b);
	l.Insert_to_tail(c);
	l.Insert_to_tail(d);
	l.getnext();
	EXPECT_EQ(l.getcurrentdate(), d);

}
/***************************************************/
 //тесты мономов и полиномов

struct monom_mod
{
	string s;
	bool iscorrect;
	Monom from_string;
	Monom real;

	monom_mod(string s, Monom real2):from_string(s)
	{
		this->s = s;
		real = real2;
		if (from_string == real) iscorrect = true; else iscorrect = false;
	}
};

class parameterizedmonom : public ::testing::TestWithParam<monom_mod>
{

};


monom_mod myarray[] = { monom_mod("3x2",Monom(3,200)), monom_mod("15y2",Monom(15,20)), monom_mod("z8",Monom(1,8)), monom_mod("-1y5x1z8",Monom(-1,158)) };

INSTANTIATE_TEST_CASE_P(instantiation1,
	parameterizedmonom,
	::testing::ValuesIn(myarray));

TEST_P(parameterizedmonom, can_create_monom_from_string)
{
		EXPECT_EQ(GetParam().iscorrect, true);
}

struct polinom_mod_pl
{
	string s;
	bool iscorrect_plus;
	polinom a;
	polinom b;
	polinom res;

	polinom_mod_pl (string s, polinom a, polinom b) : res(s)
	{
		this->s = s;
		this->a = a;
		this->b = b;
		polinom res2 = a + b;
		if  (res2 == res) iscorrect_plus = true; else iscorrect_plus = false;
	}
};

class parameterizedpolinom_plus : public ::testing::TestWithParam<polinom_mod_pl>
{
};


polinom_mod_pl myarray3[] = { polinom_mod_pl("x8",polinom("2x8"), polinom("-x8")),polinom_mod_pl("x8+y2-1",polinom("2x8+5y2+3"), polinom("-x8-4-4y2")) };

INSTANTIATE_TEST_CASE_P(instantiation2,
	parameterizedpolinom_plus,
	::testing::ValuesIn(myarray3));

TEST_P(parameterizedpolinom_plus,can_right_plus_polinoms)
{
	EXPECT_EQ(GetParam().iscorrect_plus, true);
}


struct polinom_mod_mul
{
	string s;
	bool iscorrect_mul;
	polinom a;
	polinom b;
	polinom res;

	polinom_mod_mul(string s, polinom a, polinom b) : res(s)
	{
		this->s = s;
		this->a = a;
		this->b = b;
		polinom res2 = a * b;
		if (res2 == res) iscorrect_mul = true; else iscorrect_mul = false;
	}
};

class parameterizedpolinom_multyply : public ::testing::TestWithParam<polinom_mod_mul>
{
};


polinom_mod_mul myarray4[] = { polinom_mod_mul("x8",polinom("2x2"), polinom("0.5x6")), polinom_mod_mul("z2",polinom("8z1"), polinom("0.125z1")) };

INSTANTIATE_TEST_CASE_P(instantiation3,
	parameterizedpolinom_multyply,
	::testing::ValuesIn(myarray4));

TEST_P (parameterizedpolinom_multyply, can_right_multyply_polinoms)
{
	EXPECT_EQ(GetParam().iscorrect_mul, true);
}

//************************************TABLE_TESTS***********************************************
TEST(TableUnord, can_create) 
{
	TableUnord<string, polinom> A(20);
	polinom a("1+x1");
	ASSERT_NO_THROW(A.Insert("1+x1", a));
}

class TableforCheck : public ::testing::Test
{
public:
	HashTable <string, polinom> HT;
	TableOrdered <string, polinom> TO;
	TableUnord <string, polinom> TU;

	TableforCheck() : HT(10), TO(10), TU(10)
	{
		HT.Insert("1+x1", polinom("1+x1"));
		TO.Insert("1+x1", polinom("1+x1"));
		TU.Insert("1+x1", polinom("1+x1"));
		HT.Insert("10+x1y1z1", polinom("10+x1y1z1"));
		TO.Insert("10+x1y1z1", polinom("10+x1y1z1"));
		TU.Insert("10+x1y1z1", polinom("10+x1y1z1"));
		HT.Insert("x4", polinom("x4"));
		TO.Insert("x4", polinom("x4"));
		TU.Insert("x4", polinom("x4"));
	};

};


TEST_F(TableforCheck, can_get_curr_data_TU)
{
	TU.Reset();
	polinom p("1+x1");
	EXPECT_EQ(TU.GetCurData(), p);
}

TEST_F(TableforCheck, can_get_next_TO)
{
	ASSERT_NO_THROW(TO.GetNext());
}

TEST_F(TableforCheck, can_get_next_HT)
{
	ASSERT_NO_THROW(HT.GetNext());
}

TEST_F(TableforCheck, can_get_next_TU)
{
	ASSERT_NO_THROW(TU.GetNext());
}

TEST_F(TableforCheck, can_find_existed_element_HT)
{
	EXPECT_EQ(HT.Search("1+x1")->Data, polinom("1+x1"));
}

TEST_F(TableforCheck, can_find_existed_element_TU)
{
	EXPECT_EQ(TU.Search("1+x1")->Data, polinom("1+x1"));
}

TEST_F(TableforCheck, can_find_existed_element_TO)
{
	EXPECT_EQ(TO.Search("1+x1")->Data, polinom("1+x1"));
}

TEST_F(TableforCheck, can_dell_existed_element_HT)
{
	HT.Dell("1+x1");
	ASSERT_ANY_THROW(HT.Search("1+x1"));
}

TEST_F(TableforCheck, can_dell_existed_element_TU)
{
	TU.Dell("1+x1");
	ASSERT_ANY_THROW(TU.Search("1+x1"));
}

TEST_F(TableforCheck, can_dell_existed_element_TO)
{
	TO.Dell("1+x1");
	ASSERT_ANY_THROW(TO.Search("1+x1"));
}

TEST_F(TableforCheck, can_insert_element_HT)
{
	HT.Insert("1+2x1+y1", polinom("1+2x1+y1"));
	EXPECT_EQ(HT.Search("1+2x1+y1")->Data, polinom("1+2x1+y1"));
}

TEST_F(TableforCheck, can_insert_element_TU)
{
	TU.Insert("1+z1", polinom("1+z1"));
	EXPECT_EQ(TU.Search("1+z1")->Data, polinom("1+z1"));
}

TEST_F(TableforCheck, can_insert_element_TO)
{
	TO.Insert("x1y1z1+z5", polinom("x1y1z1+z5"));
	EXPECT_EQ(TO.Search("x1y1z1+z5")->Data, polinom("x1y1z1+z5"));
}

TEST_F(TableforCheck, can_find_existed_element2_HT)
{
	EXPECT_EQ(HT.Search("10+x1y1z1")->Data, polinom("10+x1y1z1"));
}

TEST_F(TableforCheck, can_find_existed_element2_TU)
{
	EXPECT_EQ(TU.Search("10+x1y1z1")->Data, polinom("10+x1y1z1"));
}

TEST_F(TableforCheck, can_find_existed_element2_TO)
{
	EXPECT_EQ(TO.Search("10+x1y1z1")->Data, polinom("10+x1y1z1"));
}

TEST_F(TableforCheck, can_find_existed_element3_HT)
{
	EXPECT_EQ(HT.Search("x4")->Data, polinom("x4"));
}

TEST_F(TableforCheck, can_find_existed_element3_TU)
{
	EXPECT_EQ(TU.Search("x4")->Data, polinom("x4"));
}

TEST_F(TableforCheck, can_find_existed_element3_TO)
{
	EXPECT_EQ(TO.Search("x4")->Data, polinom("x4"));
}

TEST_F(TableforCheck, can_insert_element2_HT)
{
	HT.Insert("111+z1", polinom("111+z1"));
	EXPECT_EQ(HT.Search("111+z1")->Data, polinom("111+z1"));
}

TEST_F(TableforCheck, can_insert_element2_TU)
{
	TU.Insert("1+32.1x1", polinom("1+32.1x1"));
	EXPECT_EQ(TU.Search("1+32.1x1")->Data, polinom("1+32.1x1"));
}

TEST_F(TableforCheck, can_insert_element2_TO)
{
	TO.Insert("x1y1z1", polinom("x1y1z1"));
	EXPECT_EQ(TO.Search("x1y1z1")->Data, polinom("x1y1z1"));
}

TEST_F(TableforCheck, cannot_dell_element_HT)
{
	ASSERT_ANY_THROW(HT.Dell("12"));
}

TEST_F(TableforCheck, cannot_dell_element_TU)
{
	ASSERT_ANY_THROW(TU.Dell("12"));
}

TEST_F(TableforCheck, cannot_dell_element_TO)
{
	ASSERT_ANY_THROW(TO.Dell("12"));
}

TEST_F(TableforCheck, cannot_Inset_ex_element_HT)
{
	ASSERT_ANY_THROW(HT.Insert("1+x1", polinom("1+x1")));
}

TEST_F(TableforCheck, cannot_Inset_ex_element_TU)
{
	ASSERT_ANY_THROW(TU.Insert("1+x1", polinom("1+x1")));
}

TEST_F(TableforCheck, cannot_Inset_ex_element_TO)
{
	ASSERT_ANY_THROW(TO.Insert("1+x1", polinom("1+x1")));
}

TEST_F(TableforCheck, cannot_Inset_ex_element2_HT)
{
	ASSERT_ANY_THROW(HT.Insert("1+x1", polinom("1+x1")));
}

TEST_F(TableforCheck, cannot_Inset_ex_element2_TU)
{
	ASSERT_ANY_THROW(TU.Insert("1+x1", polinom("1+x1")));
}

TEST_F(TableforCheck, cannot_Inset_ex_element2_TO)
{
	ASSERT_ANY_THROW(TO.Insert("1+x1", polinom("1+x1")));
}

TEST_F(TableforCheck, jast_sotka_test_e_booy)
{
	ASSERT_ANY_THROW(TO.Dell("100"));
}
