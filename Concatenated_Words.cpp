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

// Q.Find all words that are concatenations of a list.

unordered_set<string> dict;

bool go(int i, string &word, int count)
{
    int n = word.length();

    if (i == n)
    {
        return count > 1;
    }

    string temp = "";

    while (i < n)
    {
        temp.push_back(word[i]);
        if (dict.count(temp))
        {
            if (go(i + 1, word, count + 1))
                return 1;
        }
        i++;
    }

    return false;
}

int main()
{
    dict.clear();
    int n;
    n = 7;
    string str[7] = {"tech", "lead", "techcat", "cat", "cats", "dog", "catsdog"};
    for (auto it : str)
    {
        dict.insert(it);
    }

    vector<string> ans;

    for (auto word : str)
    {
        if (go(0, word, 0))
        {
            cout << word << " ";
        }
    }

    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }

    cout << "\n";

    return 0;
}