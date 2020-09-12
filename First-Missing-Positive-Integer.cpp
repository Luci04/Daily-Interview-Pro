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

// Q .You are given an array of integers. Return the smallest positive integer that is not present in the array.
// The array may contain duplicate entries.
// For example, the input [3, 4, -1, 1] should return 2 because it is the smallest positive integer that doesn't exist in the array.

int Missing(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (abs(arr[i]) - 1 < n && arr[abs(arr[i]) - 1] > 0)
        {
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        }
    }

    for (int i = 0; i < n; i++)
        if (arr[i] > 0)
            return i + 1;

    return n + 1;
}

int solve2(int arr[], int n)
{
    int j = 0;
    int i = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    return j;
}

int solve(int arr[], int n)
{
    int shift = solve2(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << shift << "\n";

    return Missing(arr + shift, n - shift);
}

int main()
{
    int arr[] = {3, 4, -1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << solve(arr, n);
    return 0;
}