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

//Q. Given a non-negative integer n, convert the integer to hexadecimal and return the result as a string.
//  Hexadecimal is a base 16 representation of a number, where the digits are 0123456789ABCDEF.

void solve(int n)
{
    char Hexa[100];

    int i = 0;

    while (n != 0)
    {
        int temp = 0;
        temp = n % 16;
        if (temp < 10)
        {
            Hexa[i++] = temp + 48;
        }
        else
        {
            Hexa[i++] = temp + 55;
        }
        n = n / 16;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        cout << Hexa[j];
    }

    cout << "\n";
}

int main()
{
    int n;
    cin >> n;
    solve(n);
    return 0;
}