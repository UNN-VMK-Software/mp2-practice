#include "polinom.h"
#include <iostream>
using namespace std;
Polinom::Polinom(const string &S)
{
	int i = 0;
	List.Insert_to_tail(); // вставл€ем нулевую ноду
	string MonomStr = "";
	while (i + 1 <= S.length())
	{
		if ((S[i + 1] != '+') && (S[i + 1] != '-') && (S[i + 1] != '\0'))
		{
			MonomStr.push_back(S[i]);
			i += 1;
		}
		else
		{
			MonomStr.push_back(S[i]);
			monom A(MonomStr);
			if (A.coeff != 0)
				Insert(A);
			MonomStr = "";
			i++;
		}
	}
	if (List.IsEmpty())
		List.Insert_to_tail();
}

void Polinom::Insert(const monom N)
{
	int i = 0;
	int flag = 0;
	List.reset(); // ставим current в начало
	while ((!List.IsEnd()) && (flag == 0)) //пока лист не пуст 
	{
		monom M = List.getcurrentdate(); // берЄм текущий моном
		if (M.abc == N.abc) // если совпадают степени
		{
			monom res(M.abc, M.coeff + N.coeff);
			if (res.coeff != 0)
			{
				List.ChangeCurrent(res);
				flag = 1;
			}
			else
			{
				if (N.coeff != 0)
				{
					List.Dellcurrent();
					flag = 1;
				}
			}
		}
		else if ((M.abc < N.abc) && (N.abc<List.getcurrentnextdata().abc) && (flag == 0))
		{
			if (N.coeff != 0)
				List.InsertAfterCurrent(N);
			flag = 1;
		}
		List.getnext();
	}

	//последн€€ итераци€ цикла
	if ((List.IsEnd()) && (flag == 0))
	{
		monom M = List.getcurrentdate(); // берЄм текущий моном
		if (M.abc == N.abc) // если совпадают степени
		{
			monom res(M.abc, M.coeff + N.coeff);
			if (res.coeff != 0)
			{
				List.ChangeCurrent(res);
				flag = 1;
			}
			else
			{
				if (N.coeff != 0)
				{
					List.Dellcurrent();
					flag = 1;
				}
			}
		}
		else
			if (N.coeff != 0)
			{
				List.InsertAfterCurrent(N);
				flag = 1;
			}
		if (!List.IsEmpty())
			List.getnext();
	}
}

Polinom::~Polinom()
{
	List.clear();
}

Polinom::Polinom(const Polinom &A)
{
	List = A.List;

}

Polinom& Polinom :: operator=(const Polinom& Polinom2)
{
	List = Polinom2.List;
	return *this;
}

Polinom Polinom :: operator + (const Polinom& Polinom2)
{
	Polinom Res;
	this->List.reset();
	Polinom B(Polinom2);
	monom A1 = List.getcurrentdate();
	B.List.reset();
	monom B1 = B.List.getcurrentdate();
	while ((!this->List.IsEnd()) && (!B.List.IsEnd()))
	{
		if (List.getcurrentdate().abc == B.List.getcurrentdate().abc)
		{
			monom res(List.getcurrentdate().abc, List.getcurrentdate().coeff + B.List.getcurrentdate().coeff);
			if (res.coeff != 0) //при занулении коэффицентов пропускаем звено
			{
				if (res.abc == 0)
				{
					Res.Insert(res);
					List.getnext();
					B.List.getnext();
				}
				else {
					Res.List.Insert_to_tail(res);
					List.getnext();
					B.List.getnext();
				}
			}
			else
			{
				List.getnext();
				B.List.getnext();
			}
		}
		else if (List.getcurrentdate().abc < B.List.getcurrentdate().abc)
		{

			monom res(List.getcurrentdate());
			Res.List.Insert_to_tail(res);
			List.getnext();
		}
		else if (List.getcurrentdate().abc > B.List.getcurrentdate().abc)
		{
			monom res(B.List.getcurrentdate());
			Res.List.Insert_to_tail(res);
			B.List.getnext();
		}

	}
	// последн€€ итераци€ цикла
	if (List.getcurrentdate().abc == B.List.getcurrentdate().abc)
	{
		monom res(List.getcurrentdate().abc, List.getcurrentdate().coeff + B.List.getcurrentdate().coeff);
		if (res.coeff != 0) //при занулении коэффицентов пропускаем звено
		{
			if (res.abc == 0)
			{
				Res.Insert(res);
				List.getnext();
				B.List.getnext();
			}
			else
				Res.List.Insert_to_tail(res);
			List.getnext();
			B.List.getnext();
		}
		else
		{
			List.getnext();
			B.List.getnext();
		}
	}
	else if (List.getcurrentdate().abc < B.List.getcurrentdate().abc)
	{

		monom res(List.getcurrentdate());
		Res.List.Insert_to_tail(res);
		List.getnext();
	}
	else if (List.getcurrentdate().abc > B.List.getcurrentdate().abc)
	{
		monom res(B.List.getcurrentdate());
		Res.List.Insert_to_tail(res);
		B.List.getnext();
	}
	while ((this->List.getcurrentdate() != A1) && (B.List.getcurrentdate() != B1))
	{
		if (List.getcurrentdate().abc == B.List.getcurrentdate().abc)
		{
			monom res(List.getcurrentdate().abc, List.getcurrentdate().coeff + B.List.getcurrentdate().coeff);
			if (res.coeff != 0) //при занулении коэффицентов пропускаем звено
			{
				if (res.abc == 0)
				{
					Res.Insert(res);
					List.getnext();
					B.List.getnext();
				}
				else
					Res.List.Insert_to_tail(res);
				List.getnext();
				B.List.getnext();
			}
			else
			{
				List.getnext();
				B.List.getnext();
			}
		}
		else if (List.getcurrentdate().abc < B.List.getcurrentdate().abc)
		{

			monom res(List.getcurrentdate());
			Res.List.Insert_to_tail(res);
			List.getnext();
		}
		else if (List.getcurrentdate().abc > B.List.getcurrentdate().abc)
		{
			monom res(B.List.getcurrentdate());
			Res.List.Insert_to_tail(res);
			B.List.getnext();
		}


	}
	// обработка крайних случаев
	if ((this->List.getcurrentdate() == A1) && (B.List.getcurrentdate() != B1))
	{
		while (!B.List.IsEnd())
		{
			monom res(B.List.getcurrentdate());
			Res.List.Insert_to_tail(res);
			B.List.getnext();
		}
		monom res(B.List.getcurrentdate());
		Res.List.Insert_to_tail(res);
		B.List.getnext();

	}
	else if ((this->List.getcurrentdate() != A1) && (B.List.getcurrentdate() == B1))
	{

		while (!List.IsEnd())
		{
			monom res(List.getcurrentdate());
			Res.List.Insert_to_tail(res);
			List.getnext();
		}
		monom res(List.getcurrentdate());
		Res.List.Insert_to_tail(res);
		List.getnext();

	}
	
	return Res;
}
//
Polinom Polinom :: operator - (const Polinom& Polinom2)
{
	Polinom p1 = -1 * (Polinom2);
	return (*this + p1);
}
//
Polinom Polinom :: operator * (const Polinom& Polinom2)
{
	Polinom Res;
	Polinom B(Polinom2);
	List.reset();
	B.List.reset();

	while (!List.IsEnd())
	{
		while (!B.List.IsEnd())
		{
			monom res(List.getcurrentdate().abc + B.List.getcurrentdate().abc, List.getcurrentdate().coeff * B.List.getcurrentdate().coeff);
			if (res.abc > 999)
				throw "Error";
			Res.Insert(res);
			B.List.getnext();
		}
		List.getnext();
		B.List.reset();
	}

	//последн€€ итераци€ цикла
	B.List.reset();
	while (!B.List.IsEnd())
	{
		monom res(List.getcurrentdate().abc + B.List.getcurrentdate().abc, List.getcurrentdate().coeff * B.List.getcurrentdate().coeff);
		if (res.abc > 999)
			throw "Error";
		Res.Insert(res);
		B.List.getnext();
	}
	//	 
	monom res(List.getcurrentdate().abc + B.List.getcurrentdate().abc, List.getcurrentdate().coeff *B.List.getcurrentdate().coeff);
	if (res.abc > 999)
		throw "Error";;
	Res.Insert(res);
	List.reset();
	//
	while (!List.IsEnd())
	{
		monom res(List.getcurrentdate().abc + B.List.getcurrentdate().abc, List.getcurrentdate().coeff * B.List.getcurrentdate().coeff);
		if (res.abc > 999)
			throw "Error";
		Res.Insert(res);
		List.getnext();
	}
	return Res;
}

ostream& operator<<(ostream& os, const Polinom& P)
{
	int flag = 0;
	Polinom P1(P);
	P1.List.reset();
	//os << "0";
	while (!P1.List.IsEnd())
	{
		if (P1.List.getcurrentdate().coeff == 0)
			P1.List.getnext();
		else {
			flag = 1;
			if (P1.List.getcurrentdate().coeff > 0)
				os << '+';
			os << P1.List.getcurrentdate().coeff;
			string ABC = to_string(P1.List.getcurrentdate().abc);

			if (ABC.length() == 1)           // если abc =1
			{
				if (ABC == "0")
					P1.List.getnext();
				else {
					os << "z^" << ABC[0];
					P1.List.getnext();
				}
			}
			else if (ABC.length() == 2)		 // если abc =2
			{
				os << "y^" << ABC[0];
				if (ABC[1] != '0')
					os << "z^" << ABC[1];
				P1.List.getnext();
			}
			else if (ABC.length() == 3)		 // если abc =3
			{
				os << "x^" << ABC[0];
				if (ABC[1] != '0')
					os << "y^" << ABC[1];
				if (ABC[2] != '0')
					os << "z^" << ABC[2];
				P1.List.getnext();
			}
		}
	}
	// последн€€ итераци€ цикла
	if (P1.List.getcurrentdate().coeff == 0)
		P1.List.getnext();

	else {
		flag = 1;
		if (P1.List.getcurrentdate().coeff > 0)
			os << '+';
		os << P1.List.getcurrentdate().coeff;
		string ABC = to_string(P1.List.getcurrentdate().abc);

		if (ABC.length() == 1)           // если abc =1
		{
			if (ABC == "0")
				P1.List.getnext();
			else {
				os << "z^" << ABC[0];
				P1.List.getnext();
			}
		}
		else if (ABC.length() == 2)		 // если abc =2
		{
			os << "y^" << ABC[0];
			if (ABC[1] != '0')
				os << "z^" << ABC[1];
			P1.List.getnext();
		}
		else if (ABC.length() == 3)		 // если abc =3
		{
			os << "x^" << ABC[0];
			if (ABC[1] != '0')
				os << "y^" << ABC[1];
			if (ABC[2] != '0')
				os << "z^" << ABC[2];
			P1.List.getnext();
		}
	}
	if (flag == 0)
		os << "0";
	os << endl;
	return os;
}

bool Polinom :: operator==(const Polinom& Polinom2) const //оператор ==
{

	return (this->List == Polinom2.List);

}

Polinom operator * (const Polinom& A, const double a)
{
	Polinom Res;
	Polinom A1(A);
	A1.List.reset();
	while (!A1.List.IsEnd())
	{
		monom res(A1.List.getcurrentdate().abc, A1.List.getcurrentdate().coeff * a);
		if (res.coeff != 0)
			Res.Insert(res);
		A1.List.getnext();
	}
	// последн€€ итераци€ цикла
	monom res(A1.List.getcurrentdate().abc, A1.List.getcurrentdate().coeff * a);
	if (res.coeff != 0)
		Res.Insert(res);
	A1.List.getnext();
	return Res;

}
Polinom operator * (const double a, const Polinom& A)
{
	return  A * a;
}