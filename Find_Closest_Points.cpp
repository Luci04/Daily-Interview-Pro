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

// Q.Given a list of points as a tuple (x, y) and an integer k,
// find the k closest points to the origin (0, 0).

struct point
{
    int x, y;
};

bool fun(point &a, point &b)
{
    int dist1 = a.x * a.x + a.y * a.y;
    int dist2 = b.x * b.x + b.y * b.y;
    return dist1 < dist2;
}

void solve()
{
    point a[] = {{0, 0}, {1, 2}, {-3, 4}, {3, 1}};
    int k = 2;
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, a + n, fun);

    for (int i = 0; i < k; i++)
    {
        cout << a[i].x << " " << a[i].y << "\n";
    }
}

int main()
{
    solve();
    return 0;
}