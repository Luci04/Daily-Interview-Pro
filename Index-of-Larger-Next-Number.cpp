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

// Q. Given a list of numbers, for each element find the next element that is larger than
//the current element. Return the answer as a list of indices.If there are no elements larger than the current element, then use - 1 instead.

void LargerOnRight(int arr[], int n)
{
    vector<int> v;
    stack<int> st;
    st.push(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (st.empty())
        {
            st.push(arr[i]);
            continue;
        }

        while (!st.empty() && st.top() < arr[i])
        {
            v.push_back(i);
            st.pop();
        }
        st.push(arr[i]);
    }

    while (!st.empty())
    {
        v.push_back(-1);
        st.pop();
    }

    for (int x : v)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    int arr[] = {3, 2, 5, 6, 9, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    LargerOnRight(arr, n);
    return 0;
}