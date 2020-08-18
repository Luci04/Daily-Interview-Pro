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

// Q. Given a node in a binary search tree (may not be the root),
// find the next largest node in the binary search tree(also known
// as an inorder successor).The nodes in this binary search tree will also have a parent field to traverse up the tree.

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *parent;
};

Node *minValue(Node *root)
{
    while (root->left)
    {
        root = root->left;
    }
    return root;
}

Node *inorder(Node *root, Node *n)
{
    if (n->right != NULL)
        return minValue(n->right);
    Node *p = n->parent;
    while (p != NULL && n == p->right)
    {
        n = p;
        p = p->parent;
    }
    return p;
}

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->left = temp->right = temp->parent = NULL;
    temp->data = data;
    return temp;
}

Node *Insert(Node *root, int data)
{
    if (root == NULL)
        return newNode(data);
    else
    {
        Node *temp;
        if (data <= root->data)
        {
            temp = Insert(root->left, data);
            root->left = temp;
            temp->parent = root;
        }
        else
        {
            temp = Insert(root->right, data);
            root->right = temp;
            temp->parent = root;
        }
    }

    return root;
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

int main()
{
    Node *root = NULL;
    root = Insert(root, 20);
    root = Insert(root, 8);
    root = Insert(root, 22);
    root = Insert(root, 4);
    root = Insert(root, 12);
    root = Insert(root, 10);
    root = Insert(root, 14);
    Node *temp = root->left->right->right;

    Node *succ = inorder(root, temp);

    Print(root);
    cout << "\n";

    if (succ != NULL)
    {
        cout << succ->data << " ";
    }

    return 0;
}