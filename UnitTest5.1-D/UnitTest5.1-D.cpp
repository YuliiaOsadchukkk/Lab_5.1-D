#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5.1-D/Pair.cpp"
#include "../Lab_5.1-D/BitString.cpp"
#include "../Lab_5.1-D/MyException.cpp"
#include "../Lab_5.1-D/MyDerivedException.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest51D
{
	TEST_CLASS(UnitTest51D)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			BitString a, b;
			a.SetFirst(4);
			a.SetSecond(4);

			b.SetFirst(8);
			b.SetSecond(8);

			BitString c = (a ^ b);
			Assert::AreEqual(c.GetFirst(), 12l);
			Assert::AreEqual(c.GetSecond(), 12l);
		}
	};
}
