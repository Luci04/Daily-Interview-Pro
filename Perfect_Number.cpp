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

// Q.A Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.

bool solve(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }

    return sum == n;
}

bool solve1(int n)
{
    int sum = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (i * i != n)
        {
            sum += i + n / i;
        }
        else
        {
            sum += i;
        }
    }

    return sum == n;
}

int main()
{
    int n;
    cin >> n;
    cout << solve1(n) << " " << solve(n);
    return 0;
}