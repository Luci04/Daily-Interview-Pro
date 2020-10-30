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

// Q.Given a list of numbers and a target number n, find 3 numbers in the list that sums closest to the target number n.

void solve(vector<int> v, int sum)
{
    int comp = INT_MAX;
    int n = v.size();
    int x, y, z;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (abs(v[i] + v[j] + v[k] - sum) < abs(sum - comp))
                {
                    comp = v[i] + v[j] + v[k];
                    x = v[i];
                    y = v[j];
                    z = v[k];
                }
            }
        }
    }

    cout << x << " " << y << " " << z << "\n";
}

void solve1(vector<int> v, int sum)
{
    int comp = INT_MAX;
    int n = v.size();
    int x, y, z;

    sort(v.begin(), v.end());

    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            if (abs(v[i] + v[j] + v[k] - sum) < abs(sum - comp))
            {
                comp = v[i] + v[j] + v[k];
                x = v[i];
                y = v[j];
                z = v[k];
            }

            if (v[i] + v[j] + v[k] > sum)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }

    cout << x << " " << y << " " << z << "\n";
}

int main()
{
    vector<int> arr = {-1, 2, 1, -4};
    int x = 1;
    solve(arr, x);
    solve1(arr, x);
    return 0;
}