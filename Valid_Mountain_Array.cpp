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

// Q.Given an array of heights, determine whether the array forms a "mountain" pattern.
// A mountain pattern goes up and then down.

void preprocess(int arr[], int N, int left[], int right[])
{
    left[0] = 0;
    int lastIncr = 0;
    for (int i = 1; i < N; i++)
    {
        if (arr[i] > arr[i - 1])
            lastIncr = i;
        left[i] = lastIncr;
    }

    right[N - 1] = N - 1;
    int firstDec = N - 1;

    for (int i = N - 2; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1])
        {
            firstDec = i;
        }
        right[i] = firstDec;
    }
}

bool isSubarray(int arr[], int left[], int right[], int L, int R)
{
    return (right[L] >= left[R]);
}

int main()
{
    int arr[] = {2, 3, 2, 4, 4, 6, 3, 2};
    int N = sizeof(arr) / sizeof(arr[0]);

    int left[N], right[N];

    preprocess(arr, N, left, right);

    int L = 0;
    int R = 2;

    if (isSubarray(arr, left, right, L, R))
    {
        cout << "Subarray is in Mountain Form\n";
    }
    else
    {
        cout << "Subarray is not Mountain Form\n";
    }

    L = 1;
    R = 3;
    if (isSubarray(arr, left, right, L, R))
        cout << "Subarray is in Mountain form\n";
    else
        cout << "Subarray is not in Mountain form\n";

    return 0;
}