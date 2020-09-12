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

// Q. Given a list of numbers and a target number, find all possible
// unique subsets of the list of numbers that sum up to the target number.
//The numbers will all be positive numbers.

void unique_combination(int l, int sum, int K, vector<int> &local, vector<int> &A)
{
    if (sum == K)
    {
        cout << "{";
        for (int i = 0; i < local.size(); i++)
        {
            if (i != 0)
                cout << " ";
            cout << local[i];
            if (i != local.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
        return;
    }

    for (int i = l; i < A.size(); i++)
    {

        if (sum + A[i] > K)
            continue;

        if (i and A[i] == A[i - 1] and i > l)
            continue;

        local.push_back(A[i]);

        unique_combination(i + 1, sum + A[i],
                           K, local, A);

        local.pop_back();
    }
}

void Combination(vector<int> A, int K)
{
    sort(A.begin(), A.end());

    vector<int> local;

    unique_combination(0, 0, K, local, A);
}

int main()
{
    vector<int> A = {10, 1, 2, 7, 6, 1, 5};

    int K = 8;

    Combination(A, K);

    return 0;
}
