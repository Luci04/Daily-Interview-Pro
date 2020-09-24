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

bool isSame(Node *root1, Node *root2)
{
    if (root1 == NULL || root2 = NULL)
        return false;
    if (root1 == NULL && root2 == NULL)
        return true;
    return (root1->data == root2->data && isSame(root1->right, root2->right) && isSame(root1->left, root2->left));
}

vector<Node *> Dublicate(Node *root1, Node *root2)
{
    if (root2 == NULL || root1 == NULL)
        return;
    if ()
}

int main()
{

    return 0;
}