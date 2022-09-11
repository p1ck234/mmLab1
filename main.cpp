#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

const float eps = 1e-5;

double f(double x)
{
    double f = (-2 * (x + 1) * exp(-x)) + (2 * cos(-x));
    return f;
}

double MatCad(double a, double b)
{
    while (b - a > eps) {
       double m1 = a + (b - a) / 3,
          m2 = b - (b - a) / 3;
       if (f (m1) > f (m2))
          a = m1;
       else
          b = m2;
    }
    return b;
}

int main()
{
    double k = 0, a = 0.0, b = 0.0,delta = 0.0;
    double x, xp, x1, x2, h;
    int p = 0;
    cout << "x = ";
    cin >> x;
    cout << "h = ";
    cin >> h;
    x1 = x - h;
    x2 = x + h;
    if ((f(x - h) >= f(x)) && (f(x + h) >= f(x)))
    {
        a = x - h;
        b = x + h;
        p = 1;
    };
    if ((f(x - h) <= f(x)) && (f(x + h) <= f(x)))
    {
        p = 1;
    };
    xp = x;
    if ((f(x - h) > f(x)) && (f(x) > f(x + h)))
    {
        delta = h;
        a = x;
        x = x + h;
    }
    if ((f(x - h) < f(x)) && (f(x) < f(x + h)))
    {
        delta = -h;
        b = x;
        x = x - h;
    }
    while ((p != 1))
    {
        if ((f(x) < f(xp)) && (delta * h > 0))
            a = xp;
        if ((f(x) < f(xp)) && (delta * h < 0))
            b = xp;
        if ((f(x) > f(xp)) && (delta * h > 0))
        {
            b = x;
            p = 1;
        };
        if ((f(x) > f(xp)) && (delta * h < 0))
        {
            a = x;
            p = 1;
        };
        k++;
        /*cout << " Номер итерации " << k << endl;
        cout << " Ганицы отрезка a=" << a << " b=" << b << endl;*/
        xp = x;
        x = xp + pow(2.0, k - 1) * delta;
    }
    
    cout << "a = " << a << " b = " << b << endl;

    cout << MatCad(a, b) << endl;
    return 0;
}
