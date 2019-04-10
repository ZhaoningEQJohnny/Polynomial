

#pragma once
#include <iostream>
#include <string>

using namespace std;

//---------------------------------------------
//Polynomial  By Zhaoning Qiu (1876501)
//
//Poly class: Present a polynomial function, store data in array
//-allows input and output for polynomial.
//-allows to execute +, -,* for two polynomials
//-allows to check equal or not equal for two polynomials
//-allows to check or change the coefficient at special power of the polynomial
//
//Assumption :
//-User will always type -1 -1 when they want to end input,
//-if user type in multiple pairs of numbers with the same power, 
//they attend to add the two coeffcients for the same power's number 
//(e.g  2 3 2 3 -1 -1, would represent 4x^3)
//-if user uses one polynomial minus another polynomial which are the same,
//(which mean result would get 0) the result will keep the same array length as origin.
//--------------------------------------------------


class Poly
{
	//output input overload
	friend ostream& operator<<(ostream& oStr, const Poly& poly);
	friend istream& operator>>(istream& iStr, Poly& poly);

public:
	//constructors
	Poly(int coeff, int pow);			 // init with coeff and power 
	Poly(int coeff);					 // init with coeff and power with 0
	Poly();								 //init with 0 0
	Poly(const Poly& poly);				 // deep copy of a  poly

	
	~Poly();							 // deconstructor

	//operators overload

	//+ += - -= * *=
	Poly operator+(const Poly& poly) const;
	Poly& operator+=(const Poly& poly);
	Poly operator-(const Poly& poly) const;
	Poly& operator-=(const Poly& poly);
	Poly operator*(const Poly& poly) const;
	Poly& operator*=(const Poly& poly);

	
	Poly& operator=(const Poly& poly);	 //assign =

	//== !=
	bool operator==(const Poly& poly) const;
	bool operator!=(const Poly& poly) const;

	//Accessors
	int getCoeff(int pow);				 //get coeff # by pow#

	//Mutators
	bool setCoeff(int coeff, int pow);   //set coeff # by pow#

private:
	//field
	int* polyArray;
	int pLength;

};