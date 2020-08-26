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

// Q.Given a list of strings, find the list of characters that appear in all strings.s

void solve(vector<string> &v)
{
    unordered_map<char, int> mp;
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            char c = v[i][j];
            if (mp[c] == i)
            {
                mp[c]++;
            }
        }
    }

    for (auto it : mp)
    {
        if (it.second == v.size())
        {
            cout << it.first << " ";
        }
    }
}

int main()
{
    vector<string> v = {"google", "facebook", "youtube"};
    solve(v);
    return 0;
}