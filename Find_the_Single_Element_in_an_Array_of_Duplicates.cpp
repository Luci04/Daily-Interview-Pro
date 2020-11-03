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

// Q.Given an array of integers, arr, where all numbers occur twice except one number which occurs once, find the number. Your solution should ideally be O(n) time and use constant extra space.
// Example:

// Input: arr = [7, 3, 5, 5, 4, 3, 4, 8, 8]
// Output: 7

void solve(vector<int> &v)
{
    int n = v.size();
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        ans = ans ^ v[i];
    }

    cout << ans << "\n";
}

int main()
{
    vector<int> v = {1, 1, 3, 4, 4, 5, 6, 5, 6};
    solve(v);
    return 0;
}