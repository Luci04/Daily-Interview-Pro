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

// Q.Given a sorted array, convert it into a binary search tree.

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node *BST(Node *root, int left, int right, int arr[])
{
    if (left > right)
        return NULL;
    int mid = (left + right) / 2;

    root = newNode(arr[mid]);

    root->left = BST(root->left, left, mid - 1, arr);

    root->right = BST(root->right, mid + 1, right, arr);

    return root;
}

void Inorder(Node *root)
{
    if (root)
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}

int main()
{
    int arr[] = {-10, -3, 0, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = BST(root, 0, n - 1, arr);

    Inorder(root);
    return 0;
}