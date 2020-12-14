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

// Q.Hi, here's your problem today. This problem was recently asked by Uber:

// Given a number of integers, combine them so it would create the largest number.

bool fun(string &a, string &b)
{
    string str1 = a + b;
    string str2 = b + a;
    return a > b;
}

int main()
{
    int n;

    cin >> n;

    string arr[] = {"17", "7", "2", "45", "72"};

    sort(arr, arr + n, fun);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }

    cout << "\n";

    return 0;
}