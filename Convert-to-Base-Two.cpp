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

//Q.Given a non-negative integer n, convert n to base 2 in string form.
//Do not use any built in base 2 conversion functions like bin.

void print(int n)
{
    string str = "";
    while (n > 0)
    {
        str += to_string(n % 2);
        n = n / 2;
    }

    reverse(str.begin(), str.end());

    cout << str << "\n";
}

int main()
{
    int n;
    cin >> n;
    print(n);
    return 0;
}