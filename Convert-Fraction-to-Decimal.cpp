#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;

// Q.Given a numerator and a denominator, find what the equivalent decimal representation is as a string.
// If the decimal representation has recurring digits, then put those digits in brackets(ie 4 / 3 should be represented by 1.(3)to represent 1.333...).Do not use any built in evaluator functions like python's eval.
//  You can also assume that the denominator will be nonzero.

string solve(int num, int den)
{
    if (num == 0)
    {
        return "0";
    }

    int sign = (num < 0) ^ (den < 0) ? -1 : 1;

    num = abs(num);
    den = abs(den);

    int initial = num / den;

    string res;

    if (sign == -1)
        res += "-";

    res += to_string(initial);

    if (num % den == 0)
        return res;

    int rem = num % den;

    res += ".";

    map<int, int> mp;

    int index;
    bool repeated = false;

    while (rem > 0 && !repeated)
    {
        if (mp.find(rem) != mp.end())
        {
            repeated = true;
            index = mp[rem];
            break;
        }
        else
            mp[rem] = res.size();

        rem = rem * 10;

        int temp = rem / den;
        res += to_string(temp);
        rem = rem % den;
    }

    if (repeated)
    {
        res += ")";
        res.insert(index, "(");
    }

    return res;
}

int main()
{
    int num, den;
    cin >> num >> den;
    cout << solve(num, den) << "\n";
    return 0;
}