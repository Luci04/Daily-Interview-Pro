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

// Q .Given two binary numbers represented as strings, return the sum of the two binary numbers as a new binary represented as a string.
//  Do this without converting the whole binary string into an integer.

void solve(string a, string b)
{
    int i = a.length() - 1;
    int j = b.length() - 1;
    string result = "";
    int s = 0;

    while (i >= 0 || s == 1 || j >= 0)
    {
        s += (i >= 0) ? a[i] - '0' : 0;
        s += (j >= 0) ? b[j] - '0' : 0;

        result = char(s % 2 + '0') + result;

        s /= 2;

        i--, j--;
    }

    cout << result << "\n";
}

int main()
{
    string str1 = "11101", str2 = "1011";
    solve(str1, str2);
    return 0;
}