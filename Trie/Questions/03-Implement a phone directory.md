# [Implement a phone directory ](https://www.codingninjas.com/codestudio/problems/implement-a-phone-directory_1062666?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar)\

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
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

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
    
public:
    TrieNode *root;
    Trie() {
       root = new TrieNode('\0');
    }
    void insert(string word) {
        insertUtil(root, word);
    }
    
    void printSuggetion(TrieNode * curr, vector<string> & temp, string prefix){
        if(curr -> isTerminal){
            temp.push_back(prefix);
        }
        
        for(char c = 'a'; c <= 'z'; c++){
            TrieNode * next = curr -> children[c-'a'];
            if(next){
                prefix.push_back(c);
                printSuggetion(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }
    
    vector<vector<string>> getSuggetion(string query){
        TrieNode * prev = root;
        vector<vector<string>> output;
        string prefix = "";
        
        for(int i = 0; i < query.size(); i++){
            char lastch = query[i];
            
            prefix.push_back(lastch);
            
            //check for lastch
            TrieNode * curr = prev -> children[lastch - 'a'];
            
            if(curr == NULL)
                break;
            else {
                vector<string> temp;
                printSuggetion(curr, temp, prefix);
                output.push_back(temp);
                temp.clear();
                prev = curr;
            }
        }
        return output;
    }
    
};



vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.
    Trie * t = new Trie();
    for(auto contact : contactList) t -> insert(contact);
    return t->getSuggetion(queryStr);
}
```