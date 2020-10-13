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

// Q.Given a list of integers, return the bounds of the minimum range that must be sorted so that the whole list would be sorted.

void printUnsorted(int arr[], int n)
{
    int s = 0, e = n - 1, i, max, min;

    // step 1(a) of above algo
    for (s = 0; s < n - 1; s++)
    {
        if (arr[s] > arr[s + 1])
            break;
    }
    if (s == n - 1)
    {
        cout << "The complete array is sorted";
        return;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] < arr[i - 1])
        {
            e = i;
            break;
        }
    }

    int mini = arr[s];
    int maxi = arr[s];

    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] < mini)
            mini = arr[i];

        if (arr[i] > maxi)
            maxi = arr[i];
    }

    for (int i = 0; i < s; i++)
    {
        if (arr[i] > mini)
        {
            s = i;
            break;
        }
    }

    for (int i = n - 1; i >= e + 1; i--)
    {
        if (arr[i] < maxi)
        {
            e = i;
            break;
        }
    }

    cout << "The unsorted subarray which"
         << " makes the given array" << endl
         << "sorted lies between the indees "
         << s << " and " << e;
    return;
}

int main()
{
    int arr[] = {10, 12, 20, 30, 25,
                 40, 32, 31, 35, 50, 60};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printUnsorted(arr, arr_size);
    getchar();
    return 0;
}
