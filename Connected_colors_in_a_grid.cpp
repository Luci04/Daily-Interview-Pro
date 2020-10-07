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

// Q.Find the maximum number of connected colors in a grid.

int x[] = {0, 1, 0, -1};
int y[] = {1, 0, -1, 0};

bool isValid(int *arr, bool *vis, int i, int j)
{
    if (i >= 3 || i < 0 || j >= 4 || j < 0 || *(vis + i * 4 + j) == 1 || *(arr + i * 4 + j) == 0)
        return false;
    return true;
}

void dfs(int arr[][4], bool vis[][4], int i, int j, int &size)
{
    vis[i][j] = 1;
    size++;
    for (int k = 0; k < 4; k++)
    {
        int dx = x[k] + i;
        int dy = y[k] + j;
        if (isValid((int *)arr, (bool *)vis, dx, dy))
        {
            dfs(arr, vis, dx, dy, size);
        }
    }
}

int main()
{
    int arr[3][4] = {{1, 0, 0, 1},
                     {1, 1, 1, 0},
                     {0, 1, 1, 0}};

    bool vis[3][4];

    memset(vis, 0, sizeof(vis));

    int maxi = -1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] == 1 && vis[i][j] == 0)
            {
                int size = 0;
                dfs(arr, vis, i, j, size);
                maxi = max(maxi, size);
            }
        }
    }

    cout << maxi << "\n";

    return 0;
}