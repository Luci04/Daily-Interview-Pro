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

// Q.Given a binary search tree (BST) and a value s, split the BST into 2 trees, where one tree has all values less than or
// equal to s, and the other tree has all values greater than s while maintaining the tree structure of the original BST.
//  You can assume that s will be one of the node's value in the BST. Return both tree's root node as a tuple.

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void InorderArray(Node *root, vector<int> &arr)
{
    if (root)
    {
        InorderArray(root->left, arr);
        arr.push_back(root->data);
        InorderArray(root->right, arr);
    }
}

int splittingindex(vector<int> &arr, int k)
{
    int i;
    for (i = 0; i < arr.size(); i++)
    {
        if (arr[i] > k)
            break;
    }
    return i - 1;
}

void Print(Node *root)
{
    if (root)
    {
        Print(root->left);
        cout << root->data << " ";
        Print(root->right);
    }
}

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node *BuiltBST(vector<int> &arr, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;

    Node *temp = newNode(arr[mid]);

    temp->left = BuiltBST(arr, start, mid - 1);
    temp->right = BuiltBST(arr, mid + 1, end);

    return temp;
}

pair<Node *, Node *> Split(Node *root, int k)
{
    pair<Node *, Node *> p;

    if (root == NULL)
        return p;
    vector<int> arr;
    InorderArray(root, arr);

    cout << "Main Tree\n";
    Print(root);

    int x = splittingindex(arr, k);

    Node *root1 = NULL, *root2 = NULL;

    root1 = BuiltBST(arr, 0, x);

    root2 = BuiltBST(arr, x + 1, arr.size() - 1);

    p.first = root1;
    p.second = root2;

    return p;
}

int main()
{
    Node *root = NULL;
    root = newNode(3);
    root->left = newNode(1);
    root->right = newNode(4);
    root->left->right = newNode(2);
    root->right->right = newNode(5);

    pair<Node *, Node *> p;

    p = Split(root, 2);

    cout << "1.Left Side\n";
    Print(p.first);

    cout << "\n2.Right Side\n";
    Print(p.second);

    return 0;
}