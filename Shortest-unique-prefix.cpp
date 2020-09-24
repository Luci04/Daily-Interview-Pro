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

// Q .Given a list of words, for each word find the shortest unique prefix.
//  You can assume a word will not be a substring of another word (ie play and playing won't be in the same words list)

struct Trie
{
    Trie *child[26];
    int freq;
};

Trie *newNode()
{
    Trie *newnode = new Trie;
    newnode->freq = 1;
    for (int i = 0; i < 26; i++)
    {
        newnode->child[i] = NULL;
    }
    return newnode;
}

void insert(Trie *node, string str)
{
    int length = str.length();
    Trie *temp = node;

    for (int i = 0; i < str.length(); i++)
    {
        int index = str[i] - 'a';

        if (!temp->child[index])
        {
            temp->child[index] = newNode();
        }
        else
        {
            temp->child[index]->freq++;
        }

        temp = temp->child[index];
    }
}

void findPrefix(Trie *root, string str, vector<string> &ans)
{
    if (root == NULL)
        return;

    Trie *temp = root;
    string result = "";
    for (int i = 0; i < str.length(); i++)
    {
        int index = str[i] - 'a';

        if (temp->child[index]->freq == 1)
        {
            result += str[i];
            ans.push_back(result);
            temp->child[index]->freq++;
            break;
        }
        else
        {
            result += str[i];
            temp = temp->child[index];
        }
    }
}

void prefix(string arr[], int n)
{
    Trie *root = newNode();
    root->freq = 0;
    for (int i = 0; i < n; i++)
    {
        insert(root, arr[i]);
    }

    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
        findPrefix(root, arr[i], ans);
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }

    cout << endl;
}

int main()
{
    string arr[] = {"joma", "john", "jack", "techlead"};
    prefix(arr, 4);
    return 0;
}