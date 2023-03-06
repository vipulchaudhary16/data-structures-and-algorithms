#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
private:
    void insertUtil(TrieNode *root, string word)
    {
        // base case, when string got finished
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // Index, Assuming that given string is capitalized
        int ind = word[0] - 'A';
        TrieNode *child;

        if (root->children[ind] != NULL)
        {
            // present
            child = root->children[ind];
        }
        else
        {
            // absent
            child = new TrieNode(word[0]);
            root->children[ind] = child;
        }
        insertUtil(child, word.substr(1));
    }

    bool searchUtil(TrieNode *root, string word)
    {
        if (word.size() == 0)
            return root->isTerminal;

        int ind = word[0] - 'A';
        if (root->children[ind] != NULL)
            return searchUtil(root->children[ind], word.substr(1));
        else
            return false;
    }

    TrieNode *removeUtil(TrieNode *root, string word)
    {
        if (!root)
            return NULL;

        if (word.size() == 0)
        {
            if (root->isTerminal)
                root->isTerminal = false;
            if (isEmpty(root))
            {
                delete (root);
                root = NULL;
            }
            return root;
        }

        int ind = word[0] - 'A';
        root->children[ind] = removeUtil(root->children[ind], word.substr(1));
        if (isEmpty(root) and root->isTerminal == false)
        {
            delete (root);
            root = NULL;
        }
        return root;
    }

public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insert(string word)
    {
        insertUtil(root, word);
    }
    bool isEmpty(TrieNode *root)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i])
                return false;
        }
        return true;
    }
    bool search(string word)
    {
        return searchUtil(root, word);
    }
    void remove(string word)
    {
        removeUtil(root, word);
    }
};

int main()
{
    Trie *t = new Trie();
    t->insert("ABCD");
    t->insert("LOVE");

    cout << t->search("LOVE") << "\n";
    t->remove("LO");
    cout << t->search("LOVE") << "\n";
    return 0;
}