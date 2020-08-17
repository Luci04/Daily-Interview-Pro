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

struct Node
{
    int data;
    Node *next;
};

Node *swapped(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *rem = head->next->next;

    Node *newHead = head->next;

    head->next->next = head;

    head->next = swapped(rem);

    return newHead;
}

int main()
{

    return 0;
}