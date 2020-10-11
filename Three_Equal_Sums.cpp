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

// Q. Given an array of numbers, determine whether it can be partitioned into 3 arrays of equal sums.

void solve(vector<int> &v)
{
    int ind1 = -1, ind2 = -1;
    int sum = 0;

    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }

    if (sum % 3 != 0)
    {
        cout << "Not Possible\n";
        return;
    }

    int s1 = sum / 3;
    int s2 = 2 * s1;

    int preSum = 0;

    for (int i = 0; i < v.size(); i++)
    {
        preSum += v[i];

        if (preSum == s1 && ind1 == -1)
        {
            ind1 = i;
        }

        if (preSum == s2 && ind1 != -1)
        {
            ind2 = i;
            break;
        }
    }

    if (ind1 != -1 && ind2 != -1)
    {
        cout << "(" << ind1 << ", "
             << ind2 << ")";
        return;
    }
}

int main()
{
    vi v = {0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1};
    solve(v);
    return 0;
}
