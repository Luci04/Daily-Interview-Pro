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

// Q.Given a list of points and a number k, find the k closest points to the origin.

using namespace std;

class comp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        int x1 = a.first * a.first + a.second * a.second;
        int y1 = b.first * b.first + b.second * b.second;
        return x1 < y1;
    }
};

void solve(pair<int, int> points[], int n, int k)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(points[i]);
        if (pq.size() > k)
            pq.pop();
    }

    while (!pq.empty())
    {
        auto temp = pq.top();
        cout << temp.first << " " << temp.second << "\n";
        pq.pop();
    }
}

int main()
{
    pair<int, int> points[] = {{1, 3},
                               {-2, 2}};
    int n = sizeof(points) / sizeof(points[0]);
    int k = 1;
    solve(points, n, k);
    return 0;
}