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

// Q.Given a binary tree, find the minimum depth of the binary tree.
//The minimum depth is the shortest distance from the root to a leaf.

struct Node
{
    int data;
    Node *right, *left;
};

int minDepth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
        return 1;

    if (root->left == NULL)
    {
        return minDepth(root->right) + 1;
    }

    if (root->right == NULL)
    {
        return minDepth(root->left) + 1;
    }

    return min(minDepth(root->left), minDepth(root->right)) + 1;
}

int minDepth2(Node *root)
{
    if (root == NULL)
        return 0;

    queue<pair<Node *, int>> q;

    q.push({root, 1});

    while (!q.empty())
    {
        pair<Node *, int> temp;

        temp = q.front();
        q.pop();
        Node *ptr = temp.first;
        int depth = temp.second;
        if (ptr->left == NULL && ptr->right == NULL)
        {
            return depth;
        }

        if (ptr->right != NULL)
        {
            q.push({ptr->right, depth + 1});
        }

        if (ptr->left != NULL)
        {
            q.push({ptr->left, depth + 1});
        }
    }
}

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout << minDepth(root) << " " << minDepth2(root) << "\n";
    return 0;
}