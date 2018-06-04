#include "monom.h"
#include <cstdlib>
//конструктор 
monom:: monom(int abc_a, double coef_f)
{
	abc = abc_a;
	coeff = coef_f;
}

monom :: monom(const string &A)
{

	int i = 0;
	abc = 0;
	if (!determinatechar(A[0]))
	{
		string Coeff = "";
		Coeff.push_back('1');
		coeff = atof(&Coeff[0]);
	}

	while (i<A.length())
	{
		if (determinatechar(A[i]))
		{
			string Coeff = "";
			if (determinatechar(A[i]) && (!determinatechar(A[i + 1])) && (i + 1<A.length()) && (A[i + 1] != '.'))
			{
				Coeff.push_back(A[i]);
				Coeff.push_back('1');
				coeff = atof(&Coeff[0]);
				i += 1;
			}
			else
			{
				while ((determinatechar(A[i]) || A[i] == '.'))
				{
					Coeff.push_back(A[i]);
					i++;
				}
				coeff = atof(&Coeff[0]);
			}

		}
		else if ((A[i] == 'x') && (A[i + 1] == '^'))
		{
			if (!determinatecharonly(A[i + 3]))
			{
				//Set_X(A[i + 2]);
				abc = abc + 100 * (atoi(&A[i + 2]));
				i += 3;
			}
			else throw "Error_set_x";
		}
		else if ((A[i] == 'y') && (A[i + 1] == '^'))
		{
			if (!determinatecharonly(A[i + 3]))
			{
				//Set_Y(A[i + 2]);
				abc = abc + 10 * (atoi(&A[i + 2]));
				i += 3;
			}
			else throw "Error_set_y";
		}
		else if ((A[i] == 'z') && (A[i + 1] == '^'))
		{
			if (!determinatecharonly(A[i + 3]))
			{
				//Set_Z(A[i + 2]);
				abc = abc + (atoi(&A[i + 2]));
				i += 3;
			}
			else throw "Error_set_z";
		}
		else if ((A[i] == 'x') && (A[i + 1] != '^'))
		{
			//Set_X('1');
			abc = abc + 100;
			i += 1;
		}
		else if ((A[i] == 'y') && (A[i + 1] != '^'))
		{
			//Set_Y('1');
			abc = abc + 10;
			i += 1;
		}
		else if ((A[i] == 'z') && (A[i + 1] != '^'))
		{
			//Set_Z('1');
			abc = abc + 1;
			i += 1;
		}
		else i++;

	}
}
bool monom :: determinatechar(char s) //если char это цифра или знак, то вернём true;
{
	int k = s;
	if ((k>47) && (k<58)) // (k > '0') && (k <= '9') // isdigit(k) 
		return true;
	else if ((s == '+') || (s == '-'))
		return true;
	else return false;
}
bool monom :: determinatecharonly(char s) //если char это цифра, то вернём true;
{
	int k = s;
	if ((k>47) && (k<58)) // (k > '0') && (k <= '9') // isdigit(k) 
		return true;
	else return false;
}
bool monom:: operator ==(const monom &A) const
{
	if ((this->abc == A.abc)&&(coeff == A.coeff)) return 1; else return 0;
}




bool monom:: operator !=(const monom &A) const
{
	if ((this->abc == A.abc)&&(coeff==A.coeff)) return 0; else return 1;
}

bool monom:: operator <(const monom &A) const
{ 
if(this->abc < A.abc) return 1; else return 0;
}

bool monom:: operator >(const monom &A) const 
{ 
if(this->abc > A.abc) return 1; else return 0;
}


monom& monom :: operator = (const monom&A) 
{
	abc = A.abc;
	coeff = A.coeff;
	return *this;
}