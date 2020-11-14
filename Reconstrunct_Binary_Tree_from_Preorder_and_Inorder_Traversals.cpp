#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    char data;
    node *left;
    node *right;
};

int search(char arr[], int strt, int end, char value);
node *newNode(char data);

node *buildTree(char in[], char pre[], int inStart, int inEnd)
{
    static int preIndex = 0;

    if (inStart > inEnd)
        return NULL;

    node *temp = newNode(pre[preIndex++]);

    if (inStart == inEnd)
        return temp;

    int inIndex = search(in, inStart, inEnd, temp->data);

    temp->left = buildTree(in, pre, inStart, inIndex - 1);
    temp->right = buildTree(in, pre, inIndex + 1, inEnd);

    return temp;
}

int search(char arr[], int strt, int end, char value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }

    return -1;
}

node *newNode(char data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

void printInorder(node *node)
{
    if (node == NULL)
        return;

    printInorder(node->left);

    cout << node->data << " ";

    printInorder(node->right);
}

int main()
{
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int len = sizeof(in) / sizeof(in[0]);
    node *root = buildTree(in, pre, 0, len - 1);

    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(root);
}

// This is code is contributed by rathbhupendra
