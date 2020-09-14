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
//Q. Given a binary tree, and a target number, find if there is a path
//from the root to any leaf that sums up to the target.

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

bool isPath(Node *root, int sum)
{
    if (root == NULL)
    {
        return (sum == 0);
    }

    int remain = sum - (root->data);

    if (remain == 0 && root->left == NULL && root->right == NULL)
        return 1;

    bool left = isPath(root->left, remain);
    bool right = isPath(root->right, remain);

    return left || right;
}

struct Node *newnode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int main()
{

    int sum = 21;
    struct Node *root = newnode(10);
    root->left = newnode(8);
    root->right = newnode(2);
    root->left->left = newnode(3);
    root->left->right = newnode(5);
    root->right->left = newnode(2);

    if (isPath(root, sum))
        cout << "Yes\n";
    else
        cout << "NO\n";

    return 0;
}