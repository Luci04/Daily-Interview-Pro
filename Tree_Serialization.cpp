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

// Q.You are given the root of a binary tree. You need to implement 2 functions:

// 1. serialize(root) which serializes the tree into a string representation
// 2. deserialize(s) which deserializes the string back to the original tree that it represents

#define MARKER -1

using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

void serialize(Node *root, FILE *fp)
{
    if (root == NULL)
    {
        fprintf(fp, "% d ", MARKER);
        return;
    }

    fprintf(fp, " %d ", root->key);
    serialize(root->left, fp);
    serialize(root->right, fp);
}

void deSerialize(Node *&root, FILE *fp)
{
    int val;

    if (!fscanf(fp, "%d", &val) || val == MARKER)
        return;

    root = newNode(val);
    deSerialize(root->left, fp);
    deSerialize(root->right, fp);
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main()
{
    struct Node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    // Let us open a file and serialize the tree into the file
    FILE *fp = fopen("tree.txt", "w");
    if (fp == NULL)
    {
        puts("Could not open file");
        return 0;
    }
    serialize(root, fp);
    fclose(fp);

    // Let us deserialize the storeed tree into root1
    Node *root1 = NULL;
    fp = fopen("tree.txt", "r");
    deSerialize(root1, fp);

    printf("Inorder Traversal of the tree constructed from file:\n");
    inorder(root1);

    return 0;
}