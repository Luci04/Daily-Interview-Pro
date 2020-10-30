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

// Q.Find the k-th largest number in a sequence of unsorted numbers.

void solve(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        if (pq.empty())
        {
            pq.push(arr[i]);
        }
        else
        {
            pq.push(arr[i]);
        }

        if (pq.size() > 3)
            pq.pop();
    }

    cout << pq.top() << "\n";
}

int main()
{
    int arr[] = {8, 7, 2, 3, 4, 1, 5, 6, 9, 0};
    solve(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}