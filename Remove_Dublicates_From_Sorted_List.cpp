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

// Q.
// Given a sorted list of size n, with m unique elements (thus m < n),
//  modify the list such that the first m unique elements in the list will be sorted,
//  ignoring the rest of the list.
//  Your solution should have a space complexity of O(1).
//  Instead of returning the list (since you are just modifying the original list),
//  you should return what m is.

struct Node
{
    int data;
    Node *next;
};

Node *remove(Node *root)
{
    Node *curr = root;
    while (curr && curr->next)
    {
        Node *next = curr->next;
        if (next->data == curr->data)
        {
            curr->next = next->next;
            delete (next);
        }
        curr = curr->next;
    }

    return root;
}

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void print(Node *root)
{
    while (root)
    {
        cout << root->data << " ";
        root = root->next;
    }

    cout << "\n";
}

int main()
{
    Node *root = newNode(10);
    root->next = newNode(10);
    root->next->next = newNode(11);
    root->next->next->next = newNode(11);
    print(root);
    root = remove(root);
    print(root);

    return 0;
}