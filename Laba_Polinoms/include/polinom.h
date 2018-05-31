#include "monom.h"
#include "list.h"
#include <string>
using namespace std;
class polinom
{
private:
	list<Monom> mnogochlen;
	list<string>* parsing_to_string(const string &a); //parsing first level
	void Create_polinom(list<string>* a); //parsing second level
	Monom parsing_to_monom(string ptr);
public:
	polinom();
	polinom(const string &a);
	polinom(const polinom &copy);
	polinom operator + (const polinom &polinom2); 
	polinom  operator - (const polinom &polinom2);
	polinom& operator = (const polinom &polinom2);
	polinom operator * (const polinom &polinom2);
	polinom operator * (const Monom Mon);
	void delnuls(polinom &res);
	void vporydok(polinom &res);
	bool operator == (const polinom &polinom2) const;
	bool operator != (const polinom &polinom2) const;
	bool can_multyply(Monom A, Monom B);
	friend ostream& operator<<(ostream& os, const polinom& p);
	friend polinom operator * (const polinom& A, const double a);
	friend polinom operator * (const double a, const polinom& A);
};


