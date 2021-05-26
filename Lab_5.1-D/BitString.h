
//BitString.h
#pragma once
#include "Pair.h"

class BitString : public Pair
{
public:

	BitString();
	BitString(long first, long second) throw(logic_error);
	BitString(const BitString& v);

	friend BitString operator ^ (const BitString& a, const BitString& b);
	friend BitString operator << (const BitString& a, int n);
	friend BitString operator >> (const BitString& a, int n);

	BitString& operator ++() throw(MyDerivedException);
	BitString& operator --() throw(MyException);
	BitString operator ++(int) throw(MyDerivedException);
	BitString operator --(int) throw(logic_error);
};


