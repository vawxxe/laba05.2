
#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
    TEST_CLASS(UnitTest2)
    {
    public:

        TEST_METHOD(TestArctanSeries)
        {
            double x = -2.0;
            double eps = 0.0001;
            double s = 0.0;
            int n = 0;

            double a = -1.0 / x;
            s = -acos(-1.0) / 2.0;

            do
            {
                s += a;
                n++;

                double R = -(2.0 * n - 1.0) /
                    ((2.0 * n + 1.0) * x * x);

                a *= R;
            } while (fabs(a) >= eps);

            Assert::AreEqual(atan(x), s, 0.001);
        }
    };
}
