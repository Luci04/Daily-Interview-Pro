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

// Q.Given a tree, the leaves form a certain order from left to right.
// Two trees are considered "leaf-similar" if their leaf orderings are the same.

using namespace std;

struct Node
{
    int data;
    Node *right, *left;
};

void dfs(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        v.push_back(root->val);
    dfs(root->left, v);
    dfs(root->right, v);
}

bool leafSimilar(Node *root1, Node *root2)
{
    vector<int> v1{};
    vector<int> v2{};

    dfs(root1, v1);
    dfs(root2, v2);

    return v1 == v2;
}

int main()
{

    return 0;
}