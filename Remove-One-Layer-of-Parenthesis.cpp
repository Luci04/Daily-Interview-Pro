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

// Q.Remove The OuterMost parenthesis in a Valid string

string removestr(string str)
{
    string res = "", temp = "";
    int depth = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            depth++;
            if (depth > 1)
            {
                temp += '(';
            }
        }
        else
        {
            depth--;
            if (depth == 0)
            {
                res += temp;
                temp = "";
            }
            else
            {
                temp += ')';
            }
        }
    }
    return res;
}

int main()
{
    cout << removestr("(())");
    return 0;
}