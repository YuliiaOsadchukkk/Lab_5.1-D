//Pair.h
#pragma once
#pragma pack(1)
#include <string>
#include <iostream>
#include <sstream>
#include "MyException.h"
#include "MyDerivedException.h"

using namespace std;

class Pair
{
	long first;
	long second;
public:
	long GetFirst() const;
	long GetSecond() const;
	void SetFirst(long value);
	void SetSecond(long value);

	Pair();///{}
	Pair(const Pair& obj);
	Pair(const long& first, const long& second) throw(out_of_range);
	~Pair() {};

	Pair& operator = (const Pair&);
	operator string() const;

	friend ostream& operator << (ostream&, const Pair&);
	friend istream& operator >> (istream&, Pair&)  throw(MyException);

	friend bool operator == (const Pair& l, const Pair& r);
	friend bool operator != (const Pair& l, const Pair& r);
	friend bool operator > (const Pair& l, const Pair& r);
	friend bool operator < (const Pair& l, const Pair& r);
	friend bool operator >= (const Pair& l, const Pair& r);
	friend bool operator <= (const Pair& l, const Pair& r);
};
