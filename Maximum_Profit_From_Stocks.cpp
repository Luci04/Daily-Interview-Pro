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

// Q.You are given an array. Each element represents the price of a stock on that particular day. Calculate and return the maximum profit you can make from buying and selling that stock only once.

// For example: [9, 11, 8, 5, 7, 10]

// Here, the optimal trade is to buy when the price is 5, and sell when it is 10, so the return value should be 5 (profit = 10 - 5 = 5).

void solve(int arr[], int n)
{

    int mini = INT_MAX;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i] - mini);
    }

    cout << maxi << " \n";
}

int main()
{
    int arr[] = {9, 11, 8, 5, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    solve(arr, n);
    return 0;
}