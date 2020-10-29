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

//Q.Given a string with a certain rule: k[string] should be expanded to string k times. So for example, 3[abc] should be expanded to abcabcabc.
// Nested expansions can happen, so 2[a2[b]c] should be expanded to abbcabbc.

void solve(string str)
{
    stack<int> intst;
    stack<char> stringstack;
    string temp = "", result = "";

    for (int i = 0; i < str.length(); i++)
    {
        int count = 0;

        if (str[i] >= '0' && str[i] <= '9')
        {
            while (str[i] >= '0' && str[i] <= '9')
            {
                count = count * 10 + str[i] - '0';
                i++;
            }

            i--;
            intst.push(count);
        }
        else if (str[i] == ']')
        {
            temp = "";
            count = 0;

            if (!intst.empty())
            {
                count = intst.top();
                intst.pop();
            }

            while (!stringstack.empty() && stringstack.top() != '[')
            {
                temp = stringstack.top() + temp;
                stringstack.pop();
            }

            if (!stringstack.empty() && stringstack.top() == '[')
                stringstack.pop();

            for (int j = 0; j < count; j++)
                result = result + temp;

            for (int j = 0; j < result.length(); j++)
                stringstack.push(result[j]);

            result = "";
        }
        else if (str[i] == '[')
        {
            if (str[i - 1] >= '0' && str[i - 1] <= '9')
                stringstack.push(str[i]);

            else
            {
                stringstack.push(str[i]);
                intst.push(1);
            }
        }

        else
            stringstack.push(str[i]);
    }

    while (!stringstack.empty())
    {
        result = stringstack.top() + result;
        stringstack.pop();
    }

    cout << result << "\n";
}

int main()
{
    string str = "3[b]";
    solve(str);
    return 0;
}