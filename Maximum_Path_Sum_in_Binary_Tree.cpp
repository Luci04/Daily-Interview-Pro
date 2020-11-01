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

struct Node
{
    int data;
    Node *left, *right;
};

struct Node *newNode(int data)
{
    struct Node *newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return (newNode);
}

int findMaxUntil(Node *root, int &res)
{
    if (root == NULL)
        return 0;

    int l = findMaxUntil(root->left, res);
    int r = findMaxUntil(root->right, res);

    int max_single = max(max(l, r) + root->data, root->data);

    int max_top = max(max_single, l + r + root->data);

    res = max(max_top, res);

    return max_single;
}

int findMaxSum(Node *root)
{
    int res = INT_MIN;

    findMaxUntil(root, res);

    return res;
}

int main()
{

    struct Node *root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(10);
    root->left->left = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left = newNode(3);
    root->right->right->right = newNode(4);
    cout << "Max path sum is " << findMaxSum(root) << "\n";
    return 0;
}