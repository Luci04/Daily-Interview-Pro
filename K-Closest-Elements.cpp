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

//Q.Given a list of sorted numbers, and two integers k and x, find k closest numbers to the pivot x.

int find(int arr[], int start, int end, int x)
{
    if (arr[end] <= x)
        return end;
    if (arr[start] > x)
        return start;

    int mid = (start + end) / 2;

    if (arr[mid] <= x && arr[mid + 1] > x)
        return mid;

    if (arr[mid] < x)
        return find(arr, mid + 1, end, x);

    return find(arr, start, mid - 1, x);
}

void print(int arr[], int x, int k, int n)
{
    int l = find(arr, 0, n - 1, x);
    int r = l + 1;
    int count = 0;

    if (arr[l] == x)
        l--;

    while (l >= 0 && r < n && count < k)
    {
        if (x - arr[l] < arr[r] - x)
        {
            cout << arr[l--] << " ";
        }
        else
        {
            cout << arr[r++] << " ";
        }
        count++;
    }

    while (l >= 0 && count < k)
    {
        cout << arr[l--] << " ";
        count++;
    }

    while (r < n && count < k)
    {
        cout << arr[r++] << " ";
        count++;
    }
}

int main()
{
    int arr[] = {12, 16, 22, 30, 35, 39, 42,
                 45, 48, 50, 53, 55, 56};

    int n = sizeof(arr) / sizeof(arr[0]);

    int x = 35, k = 4;
    print(arr, x, k, n);

    return 0;
}