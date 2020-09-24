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

// Q. Given a sorted list with duplicates, and a target number n, find the range in which the number exists
//(represented as a tuple (low, high), both inclusive. If the number does not exist in the list, return (-1, -1)).

int firstOccurance(int arr[], int n, int x)
{
    int l = 0;
    int r = n - 1;
    int index = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == x)
        {
            index = mid;
            r = mid - 1;
        }
        else if (arr[mid] > x)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return index;
}

int lastOccurance(int arr[], int n, int x)
{
    int l = 0;
    int r = n - 1;
    int index = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == x)
        {
            index = mid;
            l = mid + 1;
        }
        else if (arr[mid] > x)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return index;
}

pair<int, int> Range(int arr[], int n, int x)
{
    pair<int, int> p;
    p.first = firstOccurance(arr, n, x);
    p.second = lastOccurance(arr, n, x);
    return p;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int find;
    cin >> find;

    pair<int, int> p = Range(arr, n, find);
    cout << p.first << " " << p.second << "\n";

    return 0;
}