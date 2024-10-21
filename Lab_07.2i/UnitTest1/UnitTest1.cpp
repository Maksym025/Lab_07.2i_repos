#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07.2i/Lab_07.2i.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int k = 2;
			const int n = 2;

		
			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];


			a[0][0] = 12;
			a[0][1] = 23;
			a[1][0] = 34;
			a[1][1] = 13;

		
			int MaxMin = FindMaxOfMinElements(a, k, n);

	
			Assert::AreEqual(13, MaxMin);

		
			for (int i = 0; i < k; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
