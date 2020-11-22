#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7.3(iter).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73iter
{
	TEST_CLASS(UnitTest73iter)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			int rowCount = 0;
			int colCount = 0;

			int** P = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				P[i] = new int[colCount];
			
			t = matrixFirstPlus(P, rowCount, colCount);

			Assert::AreEqual(t, -1);
		}
	};
}
