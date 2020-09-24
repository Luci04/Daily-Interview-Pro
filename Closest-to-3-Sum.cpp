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

// Q. Given a list of numbers and a target number n, find 3 numbers in the list that sums closest to
//the target number n.There may be multiple ways of creating the sum closest to the target number,
// you can return any combination in any order.

int solve(vector<int> &nums, int target, int &a, int &b, int &c)
{
    sort(nums.begin(), nums.end());

    int ans = 0;

    int diff = INT_MAX;

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int left = i + 1;
        int right = n - 1;
        while (left < right)
        {
            int temp = nums[left] + nums[right] + nums[i];

            if (abs(target - temp) < diff)
            {
                a = nums[left];
                b = nums[right];
                c = nums[i];
                ans = temp;
                diff = abs(target - temp);
            }
            if (temp == target)
                return temp;
            else if (temp > target)
                right--;
            else
                left++;
        }
    }

    return ans;
}

int main()
{

    vector<int> v = {2, 1, -5, 4};
    int a, b, c;
    cout << solve(v, -1, a, b, c) << "\n";
    cout << a << " " << b << " " << c << "\n";
    return 0;
}