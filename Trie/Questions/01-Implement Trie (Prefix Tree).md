# [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/)

```cpp
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

class Trie {
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
        int ind = word[0] - 'a';
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
        if(!root) return false;
        if (word.size() == 0)
            return root->isTerminal;

        int ind = word[0] - 'a';
        return searchUtil(root->children[ind], word.substr(1));
    }
    
    bool prefixUtil(TrieNode *root, string word)
    {
        if(!root) return false;
        if (word.size() == 0)
            return true;

        int ind = word[0] - 'a';
        return prefixUtil(root->children[ind], word.substr(1));
    }

    
public:
    TrieNode *root;
    
    Trie() {
       root = new TrieNode('\0');
    }
    
    void insert(string word) {
        insertUtil(root, word);
    }
    
    bool search(string word) {
        return searchUtil(root, word);
    }
    
    bool startsWith(string prefix) {
        return prefixUtil(root, prefix);
    }
};
```