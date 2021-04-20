#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5_1_G/Triangle.cpp"
#include "../Lab_5_1_G/Triad.cpp"
#include "../Lab_5_1_G/MyDerivedException.cpp"
#include "../Lab_5_1_G/MyException.cpp"
#include "../Lab_5_1_G/Object.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Labtest51G
{
	TEST_CLASS(Labtest51G)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Triangle T(3, 4, 5);
			Assert::AreEqual(T.Square(), 6.0);
		}
	};
}
