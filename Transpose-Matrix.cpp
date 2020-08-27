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

void solve(vector<vector<int>> &mat)
{
    int row = mat.size();
    int col = mat[0].size();

    vector<vector<int>> trans(col, vector<int>(row));

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            trans[i][j] = mat[j][i];
        }
    }

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << trans[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6}};
    solve(mat);
    return 0;
}