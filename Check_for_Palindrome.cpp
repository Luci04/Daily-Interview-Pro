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

// Q .Given a string, determine if there is a way to arrange the string such that the string is a palindrome.
// If such arrangement exists, return a palindrome (There could be many arrangements). Otherwise return None.

bool isPallindrome(string str)
{
    int i = 0;
    int j = str.length() - 1;

    while (i < j)
    {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }

    return true;
}

int main()
{
    string str = "momom";
    cout << isPallindrome(str) << "\n";

    return 0;
}