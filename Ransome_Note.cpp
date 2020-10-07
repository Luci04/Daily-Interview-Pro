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

// Q.Given a magazine of letters and the note he wants to write, determine whether he can construct the word.

unordered_map<char, int> mp;

bool solve(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (mp.find(str[i]) == mp.end())
            return false;
    }

    return true;
}

int main()
{
    vector<char> arr = {'a', 'b', 'c', 'd', 'e', 'f'};

    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }
    string str1 = "bed";
    string str2 = "cat";

    cout << solve(str1) << "\n";
    cout << solve(str2) << "\n";

    return 0;
}