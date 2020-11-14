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

// Q.Given a non-empty array where each element represents a digit of a non-negative
// integer, add one to the integer. The most significant digit is at the front of
// the array and each element in the array contains only one digit. Furthermore,
// the integer does not have leading zeros, except in the case of the number '0'.

void solve(vector<int> &v)
{
    int carry = 1;
    int sum;
    reverse(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        sum = carry + v[i];
        carry = sum > 9 ? 1 : 0;
        sum = sum % 10;
        v[i] = sum;
    }

    if (carry > 0)
        v.push_back(carry);

    reverse(v.begin(), v.end());

    for (auto it : v)
    {
        cout << it << " ";
    }

    cout << "\n";
}

int main()
{
    vector<int> v = {1, 2, 6};
    solve(v);

    return 0;
}