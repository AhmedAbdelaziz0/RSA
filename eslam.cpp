#include "RSA.h"
#include <bits/stdc++.h>


/// modified
void RSA::set_values()
{
    //range 16 bit
    int max = 1 << 17;
    int min = 1 << 16;

    //prime p range from 100 to 10000
    p = prime(100, 10000);

    //q that makes n in the right range
    q = prime(min/p, max/p);

    n = p*q;

    phi = (p - 1) * (q - 1);
}

void RSA::select_e()
{
    e = (rand() + 2) % phi;

    while (gcd(e, phi) != 1)
    {
        e = (rand() + 2) % phi;
    }
}

void RSA::get_d()
{
    d = mult_inv(e, phi);
}

void RSA::print_all()
{
    cout << "\np= " << p << "\nq= " << q << "\nn= " << n << "\nphi= " << phi
         << "\ne= " << e << "\nd= " << d;
}

int gcdExtended(int a, int b, int &x, int &y)
{
    // Base Case
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b % a, a, x1, y1);

    // Update x and y using results of
    // recursive call
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

int mult_inv(int a, int b)
{
    int x, y;
    if (gcdExtended(a, b, x, y) == 1)
    {
        return (x + b) % b;
    }
    else
    {
        return -1;
    }
}
