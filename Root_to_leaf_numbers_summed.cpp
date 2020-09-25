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

using namespace std;

//Q. A number can be constructed by a path from the root to a leaf.
//Given a binary tree, sum all the numbers that can be constructed from
//the root to all leaves.

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

int solve(Node *root, int sum)
{
    if (root == NULL)
        return 0;

    sum = sum * 10 + root->data;

    if (root->left == NULL && root->right == NULL)
        return sum;

    return solve(root->left, sum) + solve(root->right, sum);
}

int main()
{
    Node *root = newNode(6);
    root->left = newNode(3);
    root->right = newNode(5);
    root->left->left = newNode(2);
    root->left->right = newNode(5);
    root->right->right = newNode(4);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);
    cout << "Sum of all paths is " << solve(root, 0) << "\n";
    return 0;

    return 0;
}