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

//Q .Given an integer, reverse the digits. Do not convert the integer into a string and reverse it.

int solve(int n)
{
    int ans = 0;
    int isNeg = (n < 0) ? -1 : 1;
    if (n < 0)
        n = n * (-1);
    while (n > 0)
    {
        ans = ans * 10;
        ans += n % 10;
        n = n / 10;
    }

    return ans * isNeg;
}
int main()
{
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}