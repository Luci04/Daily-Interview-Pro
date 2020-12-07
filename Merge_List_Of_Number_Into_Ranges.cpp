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

// Q.Given a sorted list of numbers, return a list of strings that represent all of the consecutive numbers.

// Example:
// Input: [0, 1, 2, 5, 7, 8, 9, 9, 10, 11, 15]
// Output: ['0->2', '5->5', '7->11', '15->15']

using namespace std;

void solve(int arr[], int n)
{
    string ans;
    for (int i = 0; i < n;)
    {
        int start = arr[i];
        int end = arr[i];
        int j = i + 1;
        while (arr[j] == end + 1)
        {
            if (arr[j] == arr[j + 1])
            {
                j++;
            }
            else
            {
                j++;
                end++;
            }
        }
        i = j;
        ans += to_string(start) + "->" + to_string(end) + ",";
    }

    cout << ans << "\n";
}

int main()
{
    int arr1[] = {0, 1, 2, 5, 7, 8, 9, 9, 10, 11, 15};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    solve(arr1, n);
    return 0;
}