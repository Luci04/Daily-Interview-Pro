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

// Q.Given a tree, find if the binary tree is height balanced or not. A height balanced binary tree
// is a tree where every node's 2 subtree do not differ in height by more than 1.

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
};

int height(Node *node)
{
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}

bool isBalanced(Node *root)
{
    int lh, rh;

    if (root == NULL)
        return 1;

    lh = height(root->left);
    rh = height(root->right);

    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;

    return 0;
}

Node *newNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->left = node->right = NULL;

    return node;
}

bool isBalanced2(Node *root, int *height)
{
    int lh = 0, rh = 0;

    int l = 0, r = 0;

    if (root == NULL)
    {
        *height = 0;
        return 1;
    }

    l = isBalanced2(root->left, &lh);
    r = isBalanced2(root->right, &rh);

    *height = (lh > rh ? lh : rh) + 1;

    if (abs(lh - rh) >= 2)
        return 0;
    else
    {
        return l && r;
    }
}

int main()
{

    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);

    if (isBalanced(root))
        cout << "Tree is balanced\n";
    else
        cout << "Tree is not balanced\n";

    int height = 0;
    if (isBalanced2(root, &height))
        cout << "Tree is balanced\n";
    else
        cout << "Tree is not balanced\n";
    return 0;
}