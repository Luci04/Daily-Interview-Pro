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

//Q. Given an array of integers of size n, where all elements are between 1 and n inclusive, find all of the elements of [1, n] that do not appear in the array. Some numbers may appear more than once.

void solve(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int m = abs(arr[i]) - 1;
        arr[m] = arr[m] > 0 ? -arr[m] : arr[m];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            cout << i + 1 << " ";
    }
}

int main()
{
    int arr[] = {4, 6, 2, 6, 7, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    solve(arr, n);
    return 0;
}