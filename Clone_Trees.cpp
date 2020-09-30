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

//Q.Given a Original and a Cloned Tree build A function to Give back the target Node of The Cloned Tree 

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

Node *solve(Node *original, Node *cloned, Node *target)
{
    if (original == NULL)
        return NULL;
    if (original == target)
    {
        return cloned;
    }

    auto left = solve(original->left, cloned->left, target);
    if (left)
        return left;
    return solve(original->right, cloned->right, target);
}

int main()
{
    Node *original = newNode(10);
    original->left = newNode(9);
    original->right = newNode(8);
    original->left = newNode(7);
    original->left->right = newNode(6);

    Node *clone = newNode(10);
    clone->left = newNode(9);
    clone->right = newNode(8);
    clone->left = newNode(7);
    clone->left->right = newNode(6);

    Node *target = original->left->right;

    Node *ans = solve(original, clone, target);
    cout << ans->data << "\n";

    return 0;
}
