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

// Q.Given a number n, generate all possible combinations of n well-formed brackets.

bool isBalanced(string str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            st.push('(');
        else if (str[i] == ')')
        {
            if (st.empty())
                return false;
            st.pop();
        }
    }

    return st.empty();
}

void solve(int n, string str, int i)
{
    if (i == n)
    {
        if (isBalanced(str))
        {
            cout << str << "\n";
        }

        return;
    }
    str.push_back('(');
    solve(n, str, i + 1);
    str.pop_back();
    str.push_back(')');
    solve(n, str, i + 1);
}

#define MAX_SIZE 100

void efficient(int n, int pos, int open, int close)
{
    static char str[MAX_SIZE];
    if (close == n)
    {
        printf("%s\n", str);
        return;
    }
    else
    {
        if (open > close)
        {
            str[pos] = ')';
            efficient(n, pos + 1, open, close + 1);
        }
        if (open < n)
        {
            str[pos] = '(';
            efficient(n, pos + 1, open + 1, close);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    string str = "";
    solve(2 * n, str, 0);
    cout << "2nd\n";
    efficient(n, 0, 0, 0);
    return 0;
}