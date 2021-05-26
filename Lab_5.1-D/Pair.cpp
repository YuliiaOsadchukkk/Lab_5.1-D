
//Pair.cpp
#include "Pair.h"
using namespace std;

long Pair::GetFirst() const
{
	return first;
}
long Pair::GetSecond() const
{
	return second;
}
void Pair::SetFirst(long value)
{
	first = value;
}
void Pair::SetSecond(long value)
{
	second = value;
}

Pair::Pair()
	: first(0), second(0)
{}

Pair::Pair(const long& first, const long& second) throw (out_of_range)
{
	if ((first < -20 || first>20) && (second < -20 || second>20))
		throw out_of_range("Numbers must belong to [-20; 20]");

	this->first = first;
	this->second = second;
}


Pair::Pair(const Pair& obj)
{
	first = obj.first;
	second = obj.second;
}


Pair& Pair::operator = (const Pair& pr)
{
	first = pr.first;
	second = pr.second;
	return *this;
}
Pair::operator string() const
{
	stringstream ss;
	ss << first << ", " << second;
	return ss.str();
}
ostream& operator << (ostream& out, const Pair& r)
{
	out << string(r);
	return out;
}
istream& operator >> (istream& in, Pair& r) throw(MyException)
{
	long first, second;
	cout << "first = "; in >> r.first;
	cout << "second = "; in >> r.second;

	if ((r.first < -20 || r.first>20) && (r.second < -20 || r.second>20))
		throw MyException("Numbers must belong to [-20;20]");

	r.SetFirst(r.first);
	r.SetSecond(r.second);

	return in;
}


bool operator == (const Pair& A, const Pair& B)
{
	return (A.first == B.first && A.second == B.second);
}

bool operator != (const Pair& A, const Pair& B)
{
	return !(A == B);
}

bool operator > (const Pair& A, const Pair& B)
{
	return ((A.first > B.first) || (A.first == B.first && A.second > B.second));
}

bool operator < (const Pair& A, const Pair& B)
{
	return ((A.first < B.first) || (A.first == B.first && A.second < B.second));
}

bool operator >= (const Pair& A, const Pair& B)
{
	return !(A < B);
}

bool operator <= (const Pair& A, const Pair& B)
{
	return !(A > B);
}
