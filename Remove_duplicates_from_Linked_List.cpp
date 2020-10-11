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

// Q.Given a linked list, remove all duplicate values from the linked list.

// For instance, given 1 -> 2 -> 3 -> 3 -> 4, then we wish to return the linked list 1 -> 2 -> 4.

struct Node
{
    int data;
    Node *next;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->next = NULL;
    temp->data = data;
    return temp;
}

void print(Node *root)
{
    while (root)
    {
        cout << root->data << " ";
        root = root->next;
    }

    cout << endl;
}

void solve(Node *root)
{
    Node *curr = root;

    Node *next_next;

    if (curr == NULL)
        return;

    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            next_next = curr->next->next;
            delete (curr->next);
            curr->next = next_next;
        }
        else
        {
            curr = curr->next;
        }
    }
}

int main()
{
    Node *root = newNode(1);
    root->next = newNode(2);
    root->next->next = newNode(3);
    root->next->next->next = newNode(3);
    root->next->next->next->next = newNode(4);

    solve(root);

    print(root);
    return 0;
}