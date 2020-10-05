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

// Q.Given an array of size n, and all values in the array are in the range 1 to n, find all the duplicates.

void solve(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[abs(arr[i])] >= 0)
        {
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        }
        else
        {
            cout << arr[i] << " ";
        }
    }
}

int main()
{
    int arr[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    solve(arr, n);
    return 0;
}