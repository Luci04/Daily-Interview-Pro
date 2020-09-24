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

// Given a matrix that is organized such that the numbers will always be sorted
// left to right, and the first number of each row will always be greater than
// the last element of the last row (mat[i][0] > mat[i - 1][-1]),
// search for a specific value in the matrix and return whether it exists.

int solve(int arr[3][4], int x)
{
    int i = 0, j = 3;
    while (i < 3 && j >= 0)
    {
        if (arr[i][j] == x)
            return 1;
        else if (arr[i][j] > x)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return 0;
}

int main()
{
    int arr[3][4] = {{1, 3, 5, 8},
                     {10, 11, 15, 16},
                     {24, 27, 30, 31}};
    int x = 4;
    cout << solve(arr, x) << "\n";

    x = 10;
    cout << solve(arr, x) << "\n";

    return 0;
}