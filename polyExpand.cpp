#ifndef WITH_PCH_STDCPP
#include <bits/stdc++.h>
#endif
using namespace std;

/// Takes in input of the form
/// ```
/// n
/// a_1 b_1 c_1
/// a_2 b_2 c_2
/// [...]
/// a_n b_n c_n
/// ```
/// To output the coefficients of the expanded polynomial
/// f_1 + f_2 x^1 + ... + f_m x^(m-1) = (a_1 * x + b_1)^c_1 * ... * (a_n * x + b_n)^c_n
/// in the form
/// ```
/// m
/// f_1 f_2 [...] f_m
/// ```
/// This program intentionally uses signed 32-bit integers and UBSan
/// to ensure that no value exceeds the constraints of the problem


// takes in terms a,b,c -> (ax + b)^c
vector<int> expand(vector<tuple<int, int, int>> in)
{
    vector<int> out = {1};
    for (auto [a, b, c] : in)
    {
        for (int i = 0; i < c; i++)
        {
            out.push_back(out.back() * a);
            for (int j = out.size() - 2; j > 0; j--)
            {
                out[j] = (out[j - 1] * a) + (out[j] * b);
            }
            out[0] *= b;
        }
    }
    return out;
}

int main()
{
    int n;
    cin >> n;
    vector<tuple<int, int, int>> in = {};
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        in.emplace_back(a, b, c);
    }

    vector<int> out = expand(in);

    cout << out.size() << "\n";
    for (int coeff : out)
    {
        cout << coeff << " ";
    }
    cout << endl;
}
