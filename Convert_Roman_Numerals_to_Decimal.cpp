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

// Q.Given a Roman numeral, find the corresponding decimal value. Inputs will be between 1 and 3999.

int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;

    return -1;
}

int solve(string str)
{
    int n = str.length();
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        int s1 = value(str[i]);

        if (i + 1 < n)
        {
            int s2 = value(str[i + 1]);

            if (s1 >= s2)
            {
                result += s1;
            }
            else
            {
                result += s2 - s1;
                i++;
            }
        }
        else
        {
            result += s1;
        }
    }
    return result;
}

int main()
{
    string str = "MCMIV";
    cout << solve(str) << "\n";
    return 0;
}