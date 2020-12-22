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

// Q.Two words can be 'chained' if the last character of the first word is the same as the first character of the second word.

// Given a list of words, determine if there is a way to 'chain' all the words in a circle.

int M = 26;

void dfs(vector<int> g[], vector<bool> &visited, int s)
{
    visited[s] = true;

    for (int i = 0; i < g[s].size(); i++)
    {
        if (!visited[g[s][i]])
            dfs(g, visited, g[s][i]);
    }
}

bool connected(vector<int> g[], vector<int> &mark, int s)
{
    vector<bool> visited(M, false);

    dfs(g, visited, s);

    for (int i = 0; i < M; i++)
    {
        if (mark[i] && !visited[i])
            return false;
    }

    return true;
}

bool solve(string arr[], int n)
{
    vector<int> G[M];

    vector<int> mark(M, false);

    vector<int> in(M, 0), out(M, 0);

    for (int i = 0; i < n; i++)
    {
        int f = arr[i].front() - 'a';
        int l = arr[i].back() - 'a';

        mark[l] = mark[f] = true;

        out[f]++;
        in[l]++;

        G[f].push_back(l);
    }

    for (int i = 0; i < M; i++)
    {
        if (in[i] != out[i])
            return 0;
    }

    return connected(G, mark, arr[0].front() - 'a');
}

int main()
{
    string arr[] = {"ijk", "kji", "abc", "cba"};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << solve(arr, n) ? "True" : "False";
    return 0;
}