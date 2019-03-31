#include "pch.h"
#include "poly.h"
#include <vector>

using namespace std;

//constructors

// init with coeff and power 
Poly::Poly(int coeff, int pow)
{
	polyArray = new int[pow + 1];
	pLength = pow + 1;
	for (int i = 0; i < pLength; i++)
	{
		polyArray[i] = 0;
	}
	polyArray[pow] = coeff;
}
// init with coeff and power with 0
Poly::Poly(int coeff)
{
	polyArray = new int[1];
	polyArray[0] = coeff;
	pLength = 1;
}
//init with 0 0
Poly::Poly()
{
	polyArray = new int[1];
	polyArray[0] = 0;
	pLength = 1;
}
// deep copy of a  poly
Poly::Poly(const Poly& poly)
{
	polyArray = new int[poly.pLength];
	for (int i = 0; i < poly.pLength; i++)
	{
		polyArray[i] = poly.polyArray[i];
	}
	pLength = poly.pLength;
}
// deconstructor
Poly::~Poly()
{
}

//operators overload

// operator+ overload
Poly Poly::operator+(const Poly& poly) const
{
	Poly newPoly = *this;
	newPoly += poly;
	return newPoly;
}
// operator+= overload
Poly& Poly::operator+=(const Poly& poly)
{
	//switch for checking which polynomial is longer
	bool polyIsLonger = poly.pLength >= pLength;
	//retrieve max size of polynomial
	int maxSize = (polyIsLonger) ? poly.pLength : pLength;
	//temp array to get sum
	int * newArray = new int[maxSize];
	// min size of polynomial
	int minSize = (poly.pLength <= pLength) ? poly.pLength : pLength;
	//required extended size
	int extendedSize = abs(poly.pLength - pLength);
	int i;
	//assign the sum to the temp array
	for (i = 0; i < minSize; i++)
	{
		newArray[i] = polyArray[i] + poly.polyArray[i];
	}
	// replace with 0 if there's no more element in the array
	if (polyIsLonger)
	{
		for (int j = i; j < extendedSize + i; j++)
		{
			newArray[j] = poly.polyArray[j] + 0;
		}
	}
	else
	{
		for (int j = i; j < extendedSize + i; j++)
		{
			newArray[j] = polyArray[j] + 0;
		}
	}
	// deep copy the data from tempArray to this->array
	delete polyArray;
	polyArray = new int[maxSize];
	for (int j = 0; j < maxSize; j++)
	{
		polyArray[j] = newArray[j];
	}
	pLength = maxSize;
	delete newArray;
	newArray = NULL;
	return *this;
}
// operator- overload
Poly Poly::operator-(const Poly& poly) const
{
	Poly newPoly = *this;
	newPoly -= poly;
	return newPoly;
}
// operator-= overload
Poly& Poly::operator-=(const Poly& poly)
{
	//switch for checking which polynomial is longer
	bool polyIsLonger = poly.pLength >= pLength;
	//retrieve max size of polynomial
	int maxSize = (polyIsLonger) ? poly.pLength : pLength;
	//temp array to get sum
	int * newArray = new int[maxSize];
	// min size of polynomial
	int minSize = (poly.pLength <= pLength) ? poly.pLength : pLength;
	//required extended size
	int extendedSize = abs(poly.pLength - pLength);
	int i;
	//assign the sum to the temp array
	for (i = 0; i < minSize; i++)
	{
		newArray[i] = polyArray[i] - poly.polyArray[i];
	}
	// replace with 0 if there's no more element in the array
	if (polyIsLonger)
	{
		for (int j = i; j < extendedSize + i; j++)
		{
			newArray[j] = 0 - poly.polyArray[j];
		}
	}
	else
	{
		for (int j = i; j < extendedSize + i; j++)
		{
			newArray[j] = polyArray[j];
		}
	}
	// deep copy the data from tempArray to this->array
	delete polyArray;
	polyArray = new int[maxSize];
	for (int j = 0; j < maxSize; j++)
	{
		polyArray[j] = newArray[j];
	}
	pLength = maxSize;
	delete newArray;
	newArray = NULL;
	return *this;
}
// operator* overload
Poly Poly::operator*(const Poly& poly) const
{
	Poly newPoly = *this;
	newPoly *= poly;
	return newPoly;
}
// operator*= overload
Poly& Poly::operator*=(const Poly& poly)
{
	//the maxSiz is the sum of each polynomial's biggest power minus 1, because both of the polynomial has power of 0
	int maxSize = poly.pLength + pLength - 1;
	int * newArray = new int[maxSize];
	//init newArray
	for (int i = 0; i < maxSize; i++)
	{
		newArray[i] = 0;
	}


	for (int i = 0; i < pLength; i++)
	{
		for (int j = 0; j < poly.pLength; j++)
		{
			newArray[i + j] += polyArray[i] * poly.polyArray[j];
		}
	}
	// deep copy the data from tempArray to this->array
	delete polyArray;
	polyArray = new int[maxSize];
	for (int j = 0; j < maxSize; j++)
	{
		polyArray[j] = newArray[j];
	}
	pLength = maxSize;
	delete newArray;
	newArray = NULL;

	return *this;
}

// deep copy assign
Poly& Poly::operator=(const Poly& poly)
{
	int size = (poly.pLength < pLength) ? pLength : poly.pLength;
	

	int *newArray = new int[size];
	//init newArray
	for (int i = 0; i < size; i++)
	{
		newArray[i] = 0;
	}
	for (int i = 0; i < poly.pLength; i++)
	{
		newArray[i] = poly.polyArray[i];
	}

	//assign into this array
	delete polyArray;
	polyArray = new int[size];
	for (int i = 0; i < size; i++)
	{
		polyArray[i] = newArray[i];
	}

	pLength = size;
	delete newArray;
	newArray = NULL;
	return *this;
}

//  check if two poly is equal
bool Poly::operator==(const Poly& poly) const
{
	//check which length is longer
	bool thisLengthShorter = pLength < poly.pLength;
	int shortSize = (thisLengthShorter) ? pLength : poly.pLength;
	int longSize = (!thisLengthShorter) ? pLength : poly.pLength;

	//compare the elements
	for (int i = 0; i < shortSize; i++)
	{
		if (polyArray[i] != poly.polyArray[i])
		{ 
			return false;
		}
	}
	//check if the rest of elements are all 0
	if (thisLengthShorter)
	{
		for (int i = shortSize; i < longSize; i++)
		{
			if (poly.polyArray[i] != 0)
			{
				return false;
			}
		}

		return true;
	}
	else
	{
		for (int i = shortSize; i < longSize; i++)
		{
			if (polyArray[i] != 0)
			{
				return false;
			}
		}

		return true;
	}

	return false;
}
//  check if two poly is not equal
bool Poly::operator!=(const Poly& poly) const
{
	return !(*this == poly);
}

//Accessors
ostream& operator<<(ostream& oStr, const Poly& poly)
{
	int count = 0;
	for (int i = 0; i < poly.pLength; i++)
	{
		count += poly.polyArray[i];
	}
	if (count == 0)
	{
		oStr << "0";
		return oStr;
	}

	// print poly element whose power over or equal  2
	for (int i = poly.pLength - 1; i > 1; i--)
	{
		if (poly.polyArray[i] != 0)
		{
			if (poly.polyArray[i] > 0)
			{
				oStr << '+';
			}
			oStr << poly.polyArray[i] << "x^" << i;
		}
	}

	// print power=1
	if (poly.polyArray[1] != 0)
	{
		if (poly.polyArray[1] > 0)
		{
			oStr << '+';
		}
		oStr << poly.polyArray[1] << 'x';
	}

	// print power= 0
	if (poly.polyArray[0] != 0)
	{
		if (poly.polyArray[0] > 0)
		{
			oStr << '+';
		}
		oStr << poly.polyArray[0];
	}

	return oStr;
}
//get coeff by special pow number
int Poly::getCoeff(int pow)
{
	// if power over the limit  return 0
	if (pow >= pLength || pow < 0)
	{
		return 0;
	}
	return polyArray[pow];
}

// split the string into group by special character
static void SplitString(string s, vector<string>& v, const char c)
{
	int count = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == c)
		{
			v.push_back(s.substr(count, i - count));
			count = i + 1;
		}
	}
	v.push_back(s.substr(count, s.size()));
}


//Mutators
istream& operator>>(istream& iStr, Poly& poly)
{
	bool inputLoop = true;
	//get nums list from input, and retrieve the biggest power number to decide the size for poly's array
	string str = "";

	while (inputLoop)
	{
		string line = "";
		getline(iStr, line);
		if (line.size() >= 5)
		{
			inputLoop = !(line.substr(line.size() - 5, 5) == "-1 -1");
		}
		str += line;
		//if no space at last input
		if (line[line.size() - 1] !=' ') {

			str += " ";
		}
	}
	str = str.substr(0, str.size() - 1);
	vector<string> numStr;
	//split the string by space
	SplitString(str, numStr, ' ');
	int numSize = numStr.size() - 2;
	int *nums = new int[numSize];
	int bigstPow = 0;
	for (int i = 0; i < numSize; i++)
	{
		nums[i] = atoi(numStr[i].c_str());
		if (i % 2 != 0)
		{
			bigstPow = (bigstPow >= nums[i]) ? bigstPow : nums[i];
		}
	}
	int newLength = bigstPow + 1;
	//assign the info into temp array
	int *newArray = new int[newLength];
	//init newArray
	for (int i = 0; i < newLength; i++)
	{
		newArray[i] = 0;
	}

	for (int i = 0; i < numSize; i += 2)
	{
		newArray[nums[i + 1]] += nums[i];
	}

	//deep copy of temp array to assign poly's array
	delete poly.polyArray;
	poly.polyArray = new int[newLength];
	for (int j = 0; j < newLength; j++)
	{
		poly.polyArray[j] = newArray[j];
	}
	poly.pLength = newLength;

	delete nums;
	nums = NULL;
	delete newArray;
	newArray = NULL;

	return iStr;
}
bool Poly::setCoeff(int coeff, int pow)
{
	// if power is incorrect   return false
	if (pow < 0)
	{
		return false;
	}
	//if power if over the limit in this array, extend this array
	if (pow >= pLength)
	{
		int newLength = pow + 1;
		int * newArray = new int[newLength];
		for (int i = 0; i < pLength; i++)
		{
			newArray[i] = polyArray[i];
		}
		for (int i = pLength; i < pow; i++)
		{
			newArray[i] = 0;
		}
		delete polyArray;
		polyArray = new int[newLength];
		for (int i = 0; i < newLength; i++)
		{
			polyArray[i] = newArray[i];
		}
		pLength = newLength;
		delete newArray;
		newArray = NULL;
	}
	//set coeff on special pow
	polyArray[pow] = coeff;
	return true;
}