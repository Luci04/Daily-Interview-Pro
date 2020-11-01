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

void helper(vector<vector<int>> &res, vector<int> &temp, vector<int> &nums, int pos)
{
    res.push_back(temp);

    for (int i = pos; i < nums.size(); ++i)
    {
        if (i != pos && nums[i] == nums[i - 1])
            continue;
        temp.push_back(nums[i]);
        helper(res, temp, nums, i + 1);
        temp.pop_back();
    }
}
int main()
{
    vector<int> v = {1, 2, 3};

    sort(v.begin(), v.end());

    vector<vector<int>> ans;
    vector<int> curr;

    helper(ans, curr, v, 0);

    for (auto it : ans)
    {
        for (auto it2 : it)
        {
            cout << it2 << " ";
        }
        cout << "\n";
    }

    return 0;
}