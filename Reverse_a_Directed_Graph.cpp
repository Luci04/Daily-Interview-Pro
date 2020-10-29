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

// Q.Given a directed graph, reverse the directed graph so all directed edges are reversed.

void addEdge(vector<int> v[], int start, int end)
{
    v[start].push_back(end);
}

void transpose(vector<int> v[], vector<int> tran[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            addEdge(tran, v[i][j], i);
        }
    }
}

void display(vector<int> v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << "---> ";
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int n = 10;
    vector<int> org[n];
    vector<int> trans[n];
    addEdge(org, 1, 1);
    addEdge(org, 1, 4);
    addEdge(org, 1, 3);
    addEdge(org, 2, 0);
    addEdge(org, 3, 2);
    addEdge(org, 4, 1);
    addEdge(org, 4, 3);

    cout << "original graph:\n";
    display(org, n);

    cout << "\n Transpose graph:\n";
    transpose(org, trans, n);

    display(trans, n);

    return 0;
}