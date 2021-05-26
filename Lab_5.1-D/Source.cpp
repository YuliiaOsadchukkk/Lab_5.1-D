//main.cpp
#include "BitString.h"
using namespace std;

void _unexpected_to_bad()
{
	cerr << "bad_exception" << endl;
	throw;
}

BitString makeBitString(BitString c)
{
	return c;
}

void Call_Bad() throw(int)
{
	throw 'x';
}

int main()
{
	set_unexpected(_unexpected_to_bad);

	BitString o;
	int n;

	cin >> o;
	cout << o << endl << endl;

	cout << "Size of class: " << sizeof(o) << endl;

	// ShiftLeft
	cout << "How many bits do you want to shift left?" << endl;
	cout << "Input:  "; cin >> n;
	BitString a = o << n;
	cout << a << endl;

	// ShiftRight
	cout << "How many bits do you want to shift right?" << endl;
	cout << "Input:  "; cin >> n;
	BitString b = o >> n;
	cout << b << endl;

	// Xor
	cout << "Xor: " << endl;
	BitString t = (a ^ b);
	cout << t << endl << endl << endl;

	BitString L = makeBitString(t);
	cout << L << endl;

	cout << "try o--" << endl;
	try
	{
		o--;
	}
	catch (MyDerivedException a)
	{
		cerr << a.What() << endl << endl;
	}
	catch (MyDerivedException* a)
	{
		cerr << a->What() << endl << endl;
	}


	long first, second;
	cout << "first = "; cin >> first;
	cout << "second = "; cin >> second;

	BitString N(first, second);

	cout << "try N++" << endl;

	try
	{
		N++;
	}
	catch (MyException& a)
	{
		cerr << "Exception: " << a.What() << endl;
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	try
	{
		Pair K;
		cin >> K;
		cout << "K:" << endl;
		cout << K << endl;

		Pair M(-3,2);
		cout << "M:" << endl;
		cout << M << endl;

		if (K == M)
			cout << "triads are equal" << endl;
		else
			cout << "triads are not equal" << endl;

		if (K != M)
			cout << "triads are not equal" << endl;
		else
			cout << "triads are equal" << endl;

		if (K > M)
			cout << "Triad A is bigger than Triad B" << endl;
		else
			cout << "Triad A is smaller than Triad B" << endl;

		if (K < M)
			cout << "Triad A is smaller than Triad B" << endl;
		else
			cout << "Triad A is bigger than Triad B" << endl;

		if (K >= M)
			cout << "Triad A is bigger than/equal to Triad B" << endl;
		else
			cout << "Triad A is smaller than/equal to Triad B" << endl;

		if (K <= M)
			cout << "Triad A is smaller than/equal to Triad B" << endl;
		else
			cout << "Triad A is bigger than/equal to Triad B" << endl;
	}
	catch (MyException a)
	{
		cerr << "Exception: " << a.What() << endl;
	}
	catch (out_of_range& a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	try
	{
		Call_Bad();
	}
	catch (bad_exception)
	{
		cerr << "catch (bad_exception)" << endl;
	}

}
