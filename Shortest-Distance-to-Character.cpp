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

// Given a string s and a character c, find the distance for all characters in the string to the character c in the string s.
//  You can assume that the character c will appear at least once in the string.

void solve(string str, char c)
{
    int prev = INT_MAX;
    vector<int> ans;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
            prev = i;
        }

        if (prev == INT_MAX)
        {
            ans.push_back(prev);
        }
        else
        {
            ans.push_back(i - prev);
        }
    }

    prev = INT_MAX;

    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] == c)
        {
            prev = i;
        }

        if (prev != INT_MAX)
        {
            ans[i] = min(ans[i], prev - i);
        }
    }

    for (auto i : ans)
    {
        cout << i << " ";
    }

    cout << "\n";
}

int main()
{
    solve("HelloWorld", 'l');
    return 0;
}