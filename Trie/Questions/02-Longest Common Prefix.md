# [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/)

```cpp
class Solution {
public:
    int min_length(vector<string> arr){
        int mn = arr[0].size();
        for(auto str : arr)
            mn = std::min<int>(mn,str.size());
        return mn;
    }
    
    string longestCommonPrefix(vector<string>& arr) {
        int mn = min_length(arr);
        string res = "";
        for(int i = 0; i < mn; i++){
            //ith character of first string;
            char ch = arr[0][i];
            for(int j = 0; j < arr.size(); j++){
                if(arr[j][i] != ch) return res;
            }
            res.push_back(ch);
        }
        return res;
    }
};
```

## Trie Solution

```cpp

class TrieNode{
    public:
        char data;
        TrieNode * children[26];
        int childCount;
        bool isTerminal;

        TrieNode(char data){
            this -> data = data;
            this -> isTerminal = false;
            this -> childCount = 0;
            for(int i = 0; i < 26; i++){
                this -> children[i] = NULL;
            }
        }
};

class Trie{
public:
    TrieNode * root;
    
    void insertUtil(TrieNode * root, string word){
        if(word.size() == 0){
            root -> isTerminal = true;
            return;
        }
        
        int ind = word[0] - 'a';
        
        if(root -> children[ind] != NULL){
            insertUtil(root -> children[ind], word.substr(1));
        } else {
            root -> children[ind] = new TrieNode(word[0]);
            root -> childCount++;
            insertUtil(root -> children[ind], word.substr(1));
        }
    }
    
    Trie(){
        this -> root = new TrieNode('\0');
    }
    void insertWord(string word){
        insertUtil(root, word);
    }
    
    void lsp(string str, string &ans){
        for(auto c : str){
            if(root -> childCount == 1){
                ans.push_back(c);
                int ind = c - 'a';
                root = root -> children[ind];
            } else break;
            
            if(root -> isTerminal) break;
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie * t = new Trie();
        for(auto word : strs) {
            //our trie doesn't support empty string so need to handle explicitly
            if(word.empty())
                return "";
            t->insertWord(word);
        }
        
        string ans = "";
        t -> lsp(strs[0], ans);
        
        return ans;
    }
};
```