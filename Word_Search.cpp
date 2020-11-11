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

int row, col;
vector<vector<char>> Dic;

// You are given a 2D array of characters, and a target string. Return whether or not the word target word exists in the matrix. Unlike a standard word search, the word must be either going left-to-right, or top-to-bottom in the matrix.

// Example:

// [['F', 'A', 'C', 'I'],
//  ['O', 'B', 'Q', 'P'],
//  ['A', 'N', 'O', 'B'],
//  ['M', 'A', 'S', 'S']]

// Given this matrix, and the target word FOAM, you should return true, as it can be found going up-to-down in the first column.

// bool isSafe(int i, int j, int index, string str)
// {
//     if (i >= 0 && j >= 0 && i < row && j < col && str[index] == Dic[i][j])
//         return true;
//     return false;
// }

int x[] = {-1, 0, 1, 1};
int y[] = {1, 1, 0, 1};

bool dfs(int i, int j, string str)
{
    if (Dic[i][j] != str[0])
        return false;

    int len = str.length();

    for (int dir = 0; dir < 4; dir++)
    {
        int k, rd = row + x[dir], cd = col + y[dir];

        for (k = 1; k < len; k++)
        {
            if (rd >= row || rd < 0 || cd >= col || cd < 0)
                break;

            if (Dic[rd][cd] != str[k])
                break;

            rd += x[dir], cd += y[dir];
        }

        if (k == len)
            return true;
    }
    return false;
}

bool solve(vector<vector<char>> &Dic, string str)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (dfs(i, j, str))
                return true;
        }
    }

    return false;
}

int main()
{
    Dic = {{'F', 'A', 'C', 'I'},
           {'O', 'B', 'Q', 'P'},
           {'A', 'N', 'O', 'B'},
           {'M', 'A', 'S', 'S'}};

    int row = Dic.size();
    int col = Dic[0].size();

    cout << solve(Dic, "F") << "\n";

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << Dic[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}