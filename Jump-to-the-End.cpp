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

// Q.Starting at index 0, for an element n at index i, you are allowed to jump at most n indexes ahead.
//Given a list of numbers, find the minimum number of jumps to reach the end of the list.

int solve(int arr[], int n)
{

    int dp[n];
    int dp1[n];
    for (int i = 1; i < n; i++)
    {
        dp[i] = INT_MAX;
    }

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] + j >= i)
            {
                if (dp[i] > dp[j] + 1)
                {
                    dp1[i] = j;
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }

    int i = n - 1;
    while (true)
    {
        cout << i << " ";
        if (i == 0)
            break;
        i = dp1[i];
    }
    cout << "\n";

    return dp[n - 1];
}

int main()
{
    int arr[] = {3, 2, 5, 1, 1, 9, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << solve(arr, n);
    return 0;
}