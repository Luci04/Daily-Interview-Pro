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

// Q.
// Given a string, return the first recurring letter that appears. If there are no recurring letters, return None.

// Example:

// Input: qwertty
// Output: t

// Input: qwerty
// Output: None

char solve(string str)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < str.length(); i++)
    {
        mp[str[i]]++;
        if (mp[str[i]] == 2)
        {
            return str[i];
        }
    }

    return '$';
}

int main()
{
    string str;
    cin >> str;
    cout << solve(str) << "\n";
    return 0;
}