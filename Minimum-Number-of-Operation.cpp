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

// Q.You are only allowed to perform 2 operations, multiply a number by 2, or subtract a number by 1.
//Given a number x and a number y, find the minimum number of operations needed to go from x to y.

int solve(int m, int n)
{
    if (m == n)
        return 0;

    if (m > n)
        return m - n;

    if (m <= 0 && n > 0)
        return -1;

    if (n % 2 == 1)
        return 1 + solve(m, n + 1);
    else
        return 1 + solve(m, n / 2);
}

int main()
{
    cout << solve(2, 5) << "\n";
    return 0;
}