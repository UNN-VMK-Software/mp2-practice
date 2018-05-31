#include "polinom.h"
#include<iostream>
#include "list.h"
#include<monom.h>
#include<ostream>
#include<string>
using namespace std;
polinom::polinom() :mnogochlen() {
	mnogochlen.Insert_to_tail();
}
 polinom::polinom(const string &a): mnogochlen() {
	 list<string> * liststr = parsing_to_string(a);//спосок из листов
	 Create_polinom(liststr);  //создание полинома по этому списку
}
 list<string>* polinom:: parsing_to_string(const string &A) {
	 list<string>* ListMonomStr = new list<string>;
	 	int i=0;
	 	string  monomstr="";
	 	while (i < A.length()) {
	 		switch (A[i])
	 		{
	 		case '-': {
	 			if (i == 0) { monomstr.push_back(A[i++]); }
	 			else {
	 				ListMonomStr->Insert_to_tail(monomstr);
	 				monomstr = "";
	 				monomstr.push_back('-');
	 				i++;
	 			}
	 			break;
	 		}
	 		case '+': {
	 			ListMonomStr->Insert_to_tail(monomstr);
	 			monomstr = "";
	 			i++;
	 			break;
	 		}
	 		default: {
	 			monomstr.push_back(A[i++]);
	 		}
	 				 break;
	 		}
	 	}
	 	ListMonomStr->Insert_to_tail(monomstr);
	 	return ListMonomStr;
	 }
 Monom polinom:: parsing_to_monom(string ptr) {
	 Monom D(ptr);
	 return D;
 }
 void polinom::Create_polinom(list<string>* a) {
	 a->reset();
	 while (!a->IsEmpty()) {
		 //находим максимальную ноду и вставляем её в конец
		 string res;
		 a->reset();
		 res = a->getcurrentdate();
		 a->getnext();
		 while (!a->IsEnd()) {
			 if (parsing_to_monom(res) < parsing_to_monom(a->getcurrentdate())) res = a->getcurrentdate();
			 a->getnext();
		 }
		 if (parsing_to_monom(res) < parsing_to_monom(a->getcurrentdate())) res = a->getcurrentdate();
		 a->getnext();
		 //нашли максимальную ноду и вставляем её в конец
		 mnogochlen.Insert_to_tail(parsing_to_monom(res));
		 a->Delete(res);
	 }
 }
 Monom parsing_to_monom(string ptr) {
	 Monom D(ptr);
	 return D;
 }

 polinom::polinom(const polinom &copy) :mnogochlen() {
	 mnogochlen = copy.mnogochlen;
 }

 polinom& polinom:: operator = (const polinom &polinom2) {
	 mnogochlen = polinom2.mnogochlen;
	 return(*this);
 }
 polinom polinom:: operator + (const polinom &polinom2) {
	 polinom res;
	 Monom w;
	 res.mnogochlen.Delete(w);
	 polinom copy(polinom2);
	 copy.mnogochlen.reset();
	 mnogochlen.reset();
	 //начало алгоритма 	 //проверяем следующие
	 bool exit = false;
	 bool forone = true;
	 int flag = 0; // флаг на у кого в конце
	 int flag2 = 1; //флаг на единственный моном в полиноме copy
	 int flag3 = 1; //флаг на единственный моном в полиноме this
	 if(copy.mnogochlen.IsEnd())  flag2 = 0;
	 if(mnogochlen.IsEnd()) flag3 = 0;

	 while ((!copy.mnogochlen.IsEnd())&&(!mnogochlen.IsEnd())) {
		 if (copy.mnogochlen.getcurrentdate() < mnogochlen.getcurrentdate()) {
			 res.mnogochlen.Insert_to_tail(mnogochlen.getcurrentdate());
			 mnogochlen.getnext();
		 }
		 else if (copy.mnogochlen.getcurrentdate() > mnogochlen.getcurrentdate()) {
			 res.mnogochlen.Insert_to_tail(copy.mnogochlen.getcurrentdate());
			 copy.mnogochlen.getnext();
		 }
		 else {
			 if (copy.mnogochlen.getcurrentdate().f + mnogochlen.getcurrentdate().f != 0) {
				 res.mnogochlen.Insert_to_tail(Monom(copy.mnogochlen.getcurrentdate().f + mnogochlen.getcurrentdate().f, mnogochlen.getcurrentdate().abc));

			 }
			 mnogochlen.getnext();
			 copy.mnogochlen.getnext();
		 }
	 }
	 //флаг равен 1 если конец у copy
	 if ((copy.mnogochlen.IsEnd()) && (!mnogochlen.IsEnd())) flag = 1; 
	 if ((copy.mnogochlen.IsEnd()) && (mnogochlen.IsEnd())) exit = true;
	 while (exit==false) {    //когда у одного в конце надо проверять все с ним
		 if (copy.mnogochlen.getcurrentdate() < mnogochlen.getcurrentdate()) {
			 if (flag == 0) exit = true;
			 res.mnogochlen.Insert_to_tail(mnogochlen.getcurrentdate());
			 mnogochlen.getnext();
			 if (mnogochlen.IsEnd()) exit = true;
		 }
		 else if (copy.mnogochlen.getcurrentdate() > mnogochlen.getcurrentdate()) {
			 if (flag == 1) exit = true;
			 res.mnogochlen.Insert_to_tail(copy.mnogochlen.getcurrentdate());
			 copy.mnogochlen.getnext();
			 if (copy.mnogochlen.IsEnd()) exit = true;
		 }
		 else {
			 if (copy.mnogochlen.getcurrentdate().f + mnogochlen.getcurrentdate().f != 0) {
				 res.mnogochlen.Insert_to_tail(Monom(copy.mnogochlen.getcurrentdate().f + mnogochlen.getcurrentdate().f, mnogochlen.getcurrentdate().abc));
			 }
			 exit = true;
			 if (flag2 == 0 || flag3 == 0) forone = false; //значит последний использовался только что мы его обработали
			 mnogochlen.getnext();
			 copy.mnogochlen.getnext();
		 }
	 }

	   //когда они оба в цонце
	 if ((copy.mnogochlen.IsEnd() && mnogochlen.IsEnd() && forone == true)) {
		 if (copy.mnogochlen.getcurrentdate() < mnogochlen.getcurrentdate()) {
			 res.mnogochlen.Insert_to_tail(mnogochlen.getcurrentdate());
			 res.mnogochlen.Insert_to_tail(copy.mnogochlen.getcurrentdate());
			 mnogochlen.getnext();
		 }
		 else if (copy.mnogochlen.getcurrentdate() > mnogochlen.getcurrentdate()) {
			 res.mnogochlen.Insert_to_tail(copy.mnogochlen.getcurrentdate());
			 res.mnogochlen.Insert_to_tail(mnogochlen.getcurrentdate());
			 copy.mnogochlen.getnext();
		 }
		 else {
			 if (copy.mnogochlen.getcurrentdate().f + mnogochlen.getcurrentdate().f != 0) {
				 res.mnogochlen.Insert_to_tail(Monom(copy.mnogochlen.getcurrentdate().f + mnogochlen.getcurrentdate().f, mnogochlen.getcurrentdate().abc));
			 }
			 mnogochlen.getnext();
			 copy.mnogochlen.getnext();
		 }
	 }
	 else if (((flag == 1) && (!copy.mnogochlen.IsEnd()))||(flag2==0)) { //копируем всё у this а
		 while (!mnogochlen.IsEnd()) {
			 res.mnogochlen.Insert_to_tail(mnogochlen.getcurrentdate());
			 mnogochlen.getnext();
		 }
		 res.mnogochlen.Insert_to_tail(mnogochlen.getcurrentdate());
		 mnogochlen.getnext();
	 }
	 else {//копируем всё у copy а
		 while (!copy.mnogochlen.IsEnd()) {
			 res.mnogochlen.Insert_to_tail(copy.mnogochlen.getcurrentdate());
			 copy.mnogochlen.getnext();
		 }
		 res.mnogochlen.Insert_to_tail(copy.mnogochlen.getcurrentdate());
		 copy.mnogochlen.getnext();
	 }
	 if (res.mnogochlen.IsEmpty()) res.mnogochlen.Insert_to_tail();
	 return res;
 }
 polinom polinom::  operator - (const polinom &polinom2) {
	 polinom w("-1");
	 return (*this)+w*polinom2;
 }
 bool polinom:: can_multyply(Monom A, Monom B) { 
bool can = true;
	if ((A.abc/100 + B.abc/100) >= 10) can = false;
    if(((A.abc/10)%10 + (B.abc/10))%10 >= 10) can = false;
    if((A.abc % 10 + B.abc % 10) >= 10) can = false;
	return can;
}

 polinom polinom::  operator * (const polinom &polinom2) {
	 Monom w;
	 polinom copy(polinom2); //от второго
	 polinom res;
	 res.mnogochlen.Delete(w);
	 copy.mnogochlen.reset();
	 mnogochlen.reset();
	 res = (*this)*copy.mnogochlen.getcurrentdate();
	 //проверка что this единственный
	 while (!copy.mnogochlen.IsEnd()) {
		 res = res + (*this)*copy.mnogochlen.getnextcurrentdate();
		 copy.mnogochlen.getnext();
	 }
	 return res;
 }
 void polinom::delnuls(polinom &res) {
	 res.mnogochlen.reset();
	 while (!res.mnogochlen.IsEnd()) {
		 if (res.mnogochlen.getcurrentdate() == Monom(0, 0)) res.mnogochlen.Delete(Monom(0, 0));
		 res.mnogochlen.getnext();
	 }
	 if (res.mnogochlen.getcurrentdate() == Monom(0, 0)) res.mnogochlen.Delete(Monom(0, 0));
	 res.mnogochlen.getnext();
	 if (res.mnogochlen.IsEmpty()) res.mnogochlen.Insert_to_tail();
 }
 void  polinom::vporydok(polinom &res) {
	 Monom max;
	 polinom copy(res);
	 res.mnogochlen.clear();
	 while (!copy.mnogochlen.IsEmpty()) {
		 copy.mnogochlen.reset();
		 max = copy.mnogochlen.getcurrentdate();
		 copy.mnogochlen.getnext();
		 while (!copy.mnogochlen.IsEnd()) {
			 if (max < copy.mnogochlen.getcurrentdate()) max = copy.mnogochlen.getcurrentdate();
			 copy.mnogochlen.getnext();
		 }
		 if (max < copy.mnogochlen.getcurrentdate()) max = copy.mnogochlen.getcurrentdate();
		 copy.mnogochlen.Delete(max);
		 res.mnogochlen.Insert_to_tail(max);
	 }
 }

 polinom polinom:: operator * (const Monom Mon) {
	 polinom res;
	 polinom copy(*this);
	 res.mnogochlen.Delete(Monom(0, 0));
     res.mnogochlen.reset();
	 copy.mnogochlen.reset();

	 //первую умножим отдельно
	 if ((Mon.f == 0) || (copy ==polinom())) {
		 res.mnogochlen.Insert_to_tail();
	 }
	else {
		 res.mnogochlen.Insert_to_tail(copy.mnogochlen.getcurrentdate()*Mon);
		 //перемножили
		 while (!copy.mnogochlen.IsEnd()) {
			 res.mnogochlen.Insert_to_tail(copy.mnogochlen.getnextcurrentdate()*Mon);
			 copy.mnogochlen.getnext();
		 }
	 } 

	 return res;
	 
 }

 bool polinom:: operator == (const polinom &polinom2) const {
	 bool res = true;
	 polinom A(*this);
	 polinom B(polinom2);
	 A.mnogochlen.reset();
	 B.mnogochlen.reset();
	 // первые мономы проверим отдельно
	 if (A.mnogochlen.getcurrentdate() != B.mnogochlen.getcurrentdate()) res = false;
	 while (!A.mnogochlen.IsEnd() && !B.mnogochlen.IsEnd()) {
		 if (A.mnogochlen.getnextcurrentdate() != B.mnogochlen.getnextcurrentdate()) res = false;
		 A.mnogochlen.getnext();
		 B.mnogochlen.getnext();
	 }
	 if (!A.mnogochlen.IsEnd() || !B.mnogochlen.IsEnd()) res = false;
	 return res;
 }

 bool polinom:: operator != (const polinom &polinom2) const {
	 if (*this == polinom2) return 0; else return 1;
 }



 ostream& operator<<(ostream& os, const polinom& P)

 {

	 int flag = 0;

	 polinom P1(P);

	 P1.mnogochlen.reset();

	 //os << "0";

	 while (!P1.mnogochlen.IsEnd())

	 {

		 if (P1.mnogochlen.getcurrentdate().f == 0)

			 P1.mnogochlen.getnext();

		 else {

			 flag = 1;

			 if (P1.mnogochlen.getcurrentdate().f > 0)

				 os << '+';

			 os << P1.mnogochlen.getcurrentdate().f;

			 string ABC = to_string(P1.mnogochlen.getcurrentdate().abc);



			 if (ABC.length() == 1)           // если abc =1

			 {

				 if (ABC == "0")

					 P1.mnogochlen.getnext();

				 else {

					 os << "z^" << ABC[0];

					 P1.mnogochlen.getnext();

				 }

			 }

			 else if (ABC.length() == 2)                  // если abc =2

			 {

				 os << "y^" << ABC[0];

				 if (ABC[1] != '0')

					 os << "z^" << ABC[1];

				 P1.mnogochlen.getnext();

			 }

			 else if (ABC.length() == 3)                  // если abc =3

			 {

				 os << "x^" << ABC[0];

				 if (ABC[1] != '0')

					 os << "y^" << ABC[1];

				 if (ABC[2] != '0')

					 os << "z^" << ABC[2];

				 P1.mnogochlen.getnext();

			 }

		 }

	 }

	 // последняя итерация цикла

	 if (P1.mnogochlen.getcurrentdate().f == 0)

		 P1.mnogochlen.getnext();



	 else {

		 flag = 1;

		 if (P1.mnogochlen.getcurrentdate().f > 0)

			 os << '+';

		 os << P1.mnogochlen.getcurrentdate().f;

		 string ABC = to_string(P1.mnogochlen.getcurrentdate().abc);



		 if (ABC.length() == 1)           // если abc =1

		 {

			 if (ABC == "0")

				 P1.mnogochlen.getnext();

			 else {

				 os << "z^" << ABC[0];

				 P1.mnogochlen.getnext();

			 }

		 }

		 else if (ABC.length() == 2)                  // если abc =2

		 {

			 os << "y^" << ABC[0];

			 if (ABC[1] != '0')

				 os << "z^" << ABC[1];

			 P1.mnogochlen.getnext();

		 }

		 else if (ABC.length() == 3)                  // если abc =3

		 {

			 os << "x^" << ABC[0];

			 if (ABC[1] != '0')

				 os << "y^" << ABC[1];

			 if (ABC[2] != '0')

				 os << "z^" << ABC[2];

			 P1.mnogochlen.getnext();

		 }

	 }

	 if (flag == 0)

		 os << "0";

	 os << endl;

	 return os;

 }

 polinom operator * (const polinom& A, const double a)
 {
	 polinom Res;
	 polinom A1(A);
	 Res.mnogochlen.Delete(Monom(0, 0));
	 A1.mnogochlen.reset();
	 while (!A1.mnogochlen.IsEnd())
	 {
		 Monom res(A1.mnogochlen.getcurrentdate().f*a, A1.mnogochlen.getcurrentdate().abc);
		 if (res.f != 0) Res.mnogochlen.Insert_to_tail(res);
		     A1.mnogochlen.getnext();
	 }
	 // последняя итерация цикла 
	 Monom res(A1.mnogochlen.getcurrentdate().f*a, A1.mnogochlen.getcurrentdate().abc);
	 if (res.f != 0) Res.mnogochlen.Insert_to_tail(res);
	 A1.mnogochlen.getnext();
	 if (Res.mnogochlen.IsEmpty()) Res.mnogochlen.Insert_to_tail();
	 return Res;

 }
 polinom operator * (const double a, const polinom& A)
 {
	 return A * a;
 }
