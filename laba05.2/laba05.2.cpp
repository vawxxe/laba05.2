
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void S(const double x, const double eps, int& n, double& s);
void A(const double x, const int n, double& a);

int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cout << "xp = ";
    cin >> xp;

    cout << "xk = ";
    cin >> xk;

    cout << "dx = ";
    cin >> dx;

    cout << "eps = ";
    cin >> eps;

    if (xp >= -1 || xk >= -1 || xp > xk || dx <= 0 || eps <= 0)
    {
        cout << "Incorrect input!" << endl;
        return 1;
    }

    cout << fixed;
    cout << "---------------------------------------------------------------" << endl;
    cout << "|" << setw(8) << "x"
        << " |" << setw(12) << "atan(x)"
        << " |" << setw(12) << "S"
        << " |" << setw(8) << "n" << " |" << endl;
    cout << "---------------------------------------------------------------" << endl;

    x = xp;

    while (x <= xk)
    {
        S(x, eps, n, s);

        cout << "|" << setw(8) << setprecision(3) << x
            << " |" << setw(12) << setprecision(6) << atan(x)
            << " |" << setw(12) << setprecision(6) << s
            << " |" << setw(8) << n << " |" << endl;

        x += dx;
    }

    cout << "---------------------------------------------------------------" << endl;

    return 0;
}

void S(const double x, const double eps, int& n, double& s)
{
    n = 0;
    double a = -1.0 / x;
    s = -acos(-1.0) / 2.0;

    do
    {
        s += a;
        n++;
        A(x, n, a);
    } while (fabs(a) >= eps);
}

void A(const double x, const int n, double& a)
{
    double R = -(2.0 * n - 1.0) / ((2.0 * n + 1.0) * x * x);
    a *= R;
}
