#ifndef WITH_PCH_STDCPP
#include <bits/stdc++.h>
#endif
using namespace std;

// TLE solution: for each polynomial, iterate over m to find the root
// O(nmk)

// Solve f modulus m
void solve(vector<long>& f, long m)
{
    for (long i = 1; i < m; i++)
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
            cout << format("{}: {}\n", m, i);
            return;
        }
    }
}

int main()
{
    // number of polynomials, modulus
    long n, m;
    cin >> n >> m;

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

        for (long i = 2; i < m; i++)
        {
            solve(f, i);
        }
    }
}
