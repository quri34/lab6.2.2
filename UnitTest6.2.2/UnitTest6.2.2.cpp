#include "pch.h"
#include "CppUnitTest.h"
#include "..\lab6.2.2\lab6.2.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest622
{
	TEST_CLASS(UnitTest622)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[] = { 1,2,3,4 };
			int min = 0;
			int n = Min(a, 4, min, 0);
			Assert::AreEqual(n, 0);
		}
	};
}
