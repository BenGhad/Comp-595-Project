#ifndef WITH_PCH_STDCPP
#include <bits/stdc++.h>
#endif
using namespace std;

// TLE solution: for each polynomial, iterate over m to find the root
// O(nmk)

// Solve f modulus m
long solve(vector<long>& f, long m)
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
    return -1;
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
        cout << solve(f, m) << "\n";
    }
}
