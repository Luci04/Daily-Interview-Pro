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

vector<string> ans;

unordered_set<string> dict;

bool solve(string str, int index, int count)
{
    if (index == str.length())
    {
        return count > 1;
    }

    string temp = "";

    for (int i = index; i < str.length(); i++)
    {
        temp += str[i];
        if (dict.count(temp))
        {
            if (solve(str, i + 1, count + 1))
                return 1;
        }
    }
    return 0;
}

int main()
{
    string arr[] = {"rat", "cat", "cats", "dog", "catsdog", "dogcat", "dogcatrat"};

    for (auto it : arr)
    {
        dict.insert(it);
    }

    for (int i = 0; i < 7; i++)
    {
        if (solve(arr[i], 0, 0))
            cout << arr[i] << "\n";
    }

    return 0;
}