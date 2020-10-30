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

// You are given an array of integers, and an integer K. Return the subarray which sums to K.
// You can assume that a solution will always exist.

void solve(vector<int> v, int sum)
{
    int curr_sum = v[0];
    int start = 0, i;
    int n = v.size();
    for (int i = 1; i <= n; i++)
    {
        while (curr_sum > sum && start < i)
        {
            curr_sum -= v[start];
            start++;
        }

        if (curr_sum == sum)
        {
            cout << start << " " << i - 1 << endl;
        }

        if (i < n)
            curr_sum += v[i];
    }
}

int main()
{
    vector<int> v = {1, 3, 2, 5, 7, 2};
    int sum = 14;
    solve(v, 14);

    return 0;
}