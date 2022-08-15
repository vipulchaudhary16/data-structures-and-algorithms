# [Reverse Words in a String III](https://leetcode.com/problems/reverse-words-in-a-string-iii/)


```cpp
class Solution {
public:
    void reverseStr(string& str){
        int len = str.length();
        int n = len-1;
        int i = 0;
        while(i<=n){
            swap(str[i],str[n]);
            n = n-1;
            i = i+1;
        }
    }
    
    string reverseWords(string s) {
        vector<string> words;
        string res = "";
        
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            string temp = "";
            while(i < s.size() and c != ' '){
                temp += c;
                c = s[++i];
            }
            words.push_back(temp);
        }
        
        for(auto str : words){
            reverseStr(str);
            res += str;
            res += " ";
        }
        
        return res.substr(0, res.length()-1);
    }
};
```

* TC : O(n * maxLengthWord)
* Sc : o(NumberOfWords)

---
```cpp
class Solution {
public:
    string reverseWords(string s) {
        int pre = 0;
        for(int i = 0; i <= s.length(); i++){
            if(s[i] == ' ' || i == s.length()){
                reverse(s.begin() + pre, s.begin() + i);
                pre = i + 1;
            }
        }
        return s;
    }
};
```

* TC : O(n)
* SC : O(1)