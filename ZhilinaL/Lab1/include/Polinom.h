#pragma once

#include "Monom.h"
#include "List.h"
#include <iostream>
#include <string>


using namespace std;


class Polinom
{
private:
	list<monom> Plist;	
	list<monom> similar_terms(list <monom> sp);   	                                                                                    
public:
	Polinom(const string pol = "");                                                                                
	Polinom(const Polinom& pol);                           							                                 
	Polinom& operator=(const Polinom &pol);                                                                         
	Polinom operator+(const Polinom& pol) const;			                                                        
	Polinom operator*(const double a) const;				                                                      
	friend Polinom operator*(const double a, const Polinom& pol) { return pol * a; }	                               
	Polinom operator-(const Polinom& pol) const { return *this + pol * (-1.0); }		                                
	Polinom operator*(const Polinom& pol) const;			                                                        
	Polinom operator-() const { return (-1.0)*(*this); }                                                             
	friend ostream& operator<<(ostream &ostr, const Polinom &pol);	                                                
	bool operator==(const Polinom& pol) const { return Plist == pol.Plist; }
	bool operator!=(const Polinom& pol) const { return Plist != pol.Plist; }

	Polinom(list<monom> &list) : Plist(list) {}								                                  
};
