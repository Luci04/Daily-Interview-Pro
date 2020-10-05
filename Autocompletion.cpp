#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE (26)

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// Q. Given a large set of words (for instance 1,000,000 words) and then a single word prefix, find all words that it can complete to.

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];

    bool isWordEnd;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = new TrieNode;
    pNode->isWordEnd = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

void insert(struct TrieNode *root, const string key)
{
    struct TrieNode *pCrawl = root;

    for (int level = 0; level < key.length(); level++)
    {
        int index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    pCrawl->isWordEnd = true;
}

bool isLastNode(struct TrieNode *root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return 0;
    return 1;
}

void suggestionsRec(struct TrieNode *root, string currPrefix)
{
    if (root->isWordEnd)
    {
        cout << currPrefix;
        cout << endl;
    }

    if (isLastNode(root))
        return;

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i])
        {
            currPrefix.push_back(97 + i);

            suggestionsRec(root->children[i], currPrefix);
            currPrefix.pop_back();
        }
    }
}

int printAutoSuggestions(TrieNode *root, const string query)
{
    struct TrieNode *pCrawl = root;

    int level;
    int n = query.length();
    for (level = 0; level < n; level++)
    {
        int index = CHAR_TO_INDEX(query[level]);

        if (!pCrawl->children[index])
            return 0;

        pCrawl = pCrawl->children[index];
    }

    bool isLast = isLastNode(pCrawl);

    if (!isLast)
    {
        string prefix = query;
        suggestionsRec(pCrawl, prefix);
        return 1;
    }
    return 0;
}

int main()
{
    struct TrieNode *root = getNode();
    insert(root, "hello");
    insert(root, "dog");
    insert(root, "hell");
    insert(root, "cat");
    insert(root, "a");
    insert(root, "hel");
    insert(root, "help");
    insert(root, "helps");
    insert(root, "helping");
    printAutoSuggestions(root, "hel");

    return 0;
}
