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

// Q .Given a binary tree, find and return the largest path from root to le

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

vector<int> Path(Node *root)
{
    if (root == NULL)
    {
        vector<int> temp = {};
        return temp;
    }

    vector<int> leftMost = Path(root->left);
    vector<int> rightMost = Path(root->right);

    if (leftMost.size() > rightMost.size())
        leftMost.push_back(root->data);
    else
        rightMost.push_back(root->data);

    return leftMost.size() < rightMost.size() ? rightMost : leftMost;
}

int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->right = newNode(6);

    vector<int> output = Path(root);
    int n = output.size();

    for (int i = n - 1; i >= 0; i--)
        cout << output[i] << " ";

    return 0;
}