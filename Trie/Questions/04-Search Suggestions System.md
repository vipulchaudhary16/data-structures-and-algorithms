# [Search Suggestions System](https://leetcode.com/problems/search-suggestions-system/)

```cpp
struct TrieNode{
    bool isTerminal = false;
    TrieNode * children[26] = {NULL};
};

class Solution {
public:
    void insertWord(TrieNode * trie, string & word){
        for(char &c : word){
            int index = c - 'a';
            if(trie -> children[index] == NULL)
                trie -> children[index] = new TrieNode;
            trie = trie -> children[index];
        }
        trie -> isTerminal = true;
    }
    
    vector<string> searchWord(TrieNode * trie, string &pre){
        vector<string> res;
        for(char &c : pre){
            int index = c - 'a';
            if(trie -> children[index] == NULL) return {};
            trie = trie -> children[index];
        }
        dfs(trie, pre, res);
        return res;
    }
    
    void dfs(TrieNode *trie, string pre, vector<string> &result) {
        if (result.size() == 3)
            return;
        if (trie->isTerminal)
            result.push_back(pre);
        
        for (int i = 0; i < 26; i++) {
            if (trie->children[i])
                dfs(trie->children[i], pre + (char)(i + 'a'), result);
        }
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string search) {
        vector<vector<string>> result;
        TrieNode * trie = new TrieNode;
        for(string &s : products) insertWord(trie, s);
        
        string prefix;
        for(char &c : search){
            prefix += c;
            result.push_back(searchWord(trie, prefix));
        }
        return result;
    }
};
```