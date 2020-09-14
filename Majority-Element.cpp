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

//Q. A majority element is an element that appears more than half the time.
// Given a list with a majority element, find the majority element.

int solve(int arr[], int n)
{
    int result = arr[0];
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (result == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }

        if (count == 0)
        {
            result = arr[i];
            count = 1;
        }
    }

    return result;
}

int main()
{
    int arr[] = {3, 5, 3, 3, 2, 4, 3};
    cout << solve(arr, 7);
    return 0;
}