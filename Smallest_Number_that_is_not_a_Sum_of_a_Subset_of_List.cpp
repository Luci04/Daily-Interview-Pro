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

// Q.Given a sorted list of positive numbers, find the smallest positive number that cannot be a sum of any subset in the list.

int solve(int arr[], int n)
{
    int res = 1;
    for (int i = 0; i < n && arr[i] <= res; i++)
    {
        res = res + arr[i];
    }

    return res;
}

int main()
{
    int arr[] = {1, 2, 3, 8, 9, 10};
    cout << solve(arr, 6) << "\n";
    return 0;
}