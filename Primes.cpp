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

// Q. Given a positive integer n, find all primes less than n.

bool primes[100000001];

void seive()
{
    memset(primes, true, sizeof(primes));

    for (int p = 2; p * p <= 100000001; p++)
    {
        if (primes[p] == true)
        {
            for (int i = p * p; i <= 100000001; i += p)
            {
                primes[i] = false;
            }
        }
    }
}

int main()
{
    seive();
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (primes[i])
            cout << i << " ";
    }

    cout << "\n";
    return 0;
}