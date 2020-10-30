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

// Q.A unival tree is a tree where all the nodes have the same value.
// Given a binary tree, return the number of unival subtrees in the tree.

struct Node
{
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

bool countSingRec(Node *root, int &count)
{
    if (root == NULL)
        return true;

    bool left = countSingRec(root->left, count);
    bool right = countSingRec(root->right, count);

    if (left == false || right == false)
        return false;

    if (root->left && root->data != root->left->data)
        return false;

    if (root->right && root->data != root->right->data)
        return false;

    count++;

    return true;
}

int countSing(Node *root)
{
    int count = 0;
    countSingRec(root, count);
    return count;
}

int main()
{

    Node *root = newNode(5);
    root->left = newNode(4);
    root->right = newNode(5);
    root->left->left = newNode(4);
    root->left->right = newNode(4);
    root->right->right = newNode(5);

    cout << countSing(root) << endl;

    return 0;
}