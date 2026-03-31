#ifndef WITH_PCH_STDCPP
#include <bits/stdc++.h>
#endif
using namespace std;

// WA solution: for each polynomial, factor it
// and solve modulo each prime, then apply CRT.
// CRT does not solve for repeated prime factors

long euclid(long a, long b, long& x, long& y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    long d = euclid(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

long crt(long a, long m, long b, long n)
{
    if (n > m)
    {
        swap(a, b);
        swap(m, n);
    }
    long x, y, g = euclid(m, n, x, y);
    assert((a - b) % g == 0); // else no solution
    x = (b - a) % n * x % n / g * m + a;
    return x < 0 ? x + m * n / g : x;
}

unsigned long modmul(unsigned long a, unsigned long b, unsigned long M)
{
    long ret = a * b - M * (unsigned long)(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (long)M);
}
unsigned long modpow(unsigned long b, unsigned long e, unsigned long mod)
{
    unsigned long ans = 1;
    for (; e; b = modmul(b, b, mod), e /= 2)
    {
        if (e & 1)
        {
            ans = modmul(ans, b, mod);
        }
    }
    return ans;
}

bool isPrime(unsigned long n)
{
    if (n < 2 || n % 6 % 4 != 1)
    {
        return (n | 1) == 3;
    }
    unsigned long A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    unsigned long s = __builtin_ctzll(n - 1);
    unsigned long d = n >> s;
    for (unsigned long a : A)
    {
        unsigned long p = modpow(a % n, d, n);
        unsigned long i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
        {
            p = modmul(p, p, n);
        }
        if (p != n - 1 && i != s)
        {
            return 0;
        }
    }
    return 1;
}

unsigned long pollard(unsigned long n)
{
    unsigned long x = 0, y = 0, t = 30, prd = 2, i = 1, q;
    auto f = [&](unsigned long x) { return modmul(x, x, n) + i; };
    while (t++ % 40 || __gcd(prd, n) == 1)
    {
        if (x == y)
        {
            x = ++i, y = f(x);
        }
        if ((q = modmul(prd, max(x, y) - min(x, y), n)))
        {
            prd = q;
        }
        x = f(x);
        y = f(f(y));
    }
    return __gcd(prd, n);
}

vector<unsigned long> factor(unsigned long n)
{
    if (n == 1)
    {
        return {};
    }
    if (isPrime(n))
    {
        return {n};
    }
    unsigned long x = pollard(n);
    vector<unsigned long> l = factor(x);
    vector<unsigned long> r = factor(n / x);
    l.insert(l.end(), r.begin(), r.end());
    return l;
}

// Solve f modulus m by iteration
long solveSmall(vector<long>& f, long m)
{
    for (long i = 0; i < m; i++)
    {
        long prod = 0;
        long t = 1;
        for (long coeff : f)
        {
            prod = (prod + ((t * coeff) % m)) % m;
            t = (t * i) % m;
        }
        if (prod == 0)
        {
            return i;
        }
    }
    __builtin_abort();
}

// Solve f modulus m by solving over factors then CRT
long solveLarge(vector<long>& f, vector<long>& factors)
{
    long res = solveSmall(f, factors[0]);
    long m = factors[0];
    for (long i = 1; i < factors.size(); i++)
    {
        long t = solveSmall(f, factors[i]);
        res = crt(res, m, t, factors[i]);
        m *= factors[i];
    }
    return res;
}

int main()
{
    // number of polynomials, modulus
    long n, m;
    cin >> n >> m;

    vector<unsigned long> ufacs = factor(m);
    vector<long> facs = {ufacs.begin(), ufacs.end()};

    while (n--)
    {
        long k;
        cin >> k;
        vector<long> f = {};
        for (long i = 0; i < k; i++)
        {
            long fi;
            cin >> fi;
            f.push_back(fi);
        }
        cout << solveLarge(f, facs) << "\n";
    }
}
