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

//Q. Given a string, determine if you can remove any character to create a palindrome.

bool isPalindrome(string::iterator low, string::iterator high)
{
    while (low < high)
    {
        if (*low != *high)
            return false;
        low++;
        high--;
    }
    return true;
}

int solve(string str)
{
    int low = 0;
    int high = str.length() - 1;
    while (low < high)
    {
        if (str[low] == str[high])
        {
            low++;
            high--;
        }
        else
        {
            if (isPalindrome(str.begin() + low + 1, str.begin() + high))
                return low;
            if (isPalindrome(str.begin() + low, str.begin() + high - 1))
                return high;
        }
    }
    return -2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        int index = solve(str);
        if (index == -1)
            cout << "False\n";
        else
        {
            cout << "True\n";
        }
    }

    return 0;
}