### [Repeat and Missing Number Array](https://www.interviewbit.com/problems/repeat-and-missing-number-array/)

```cpp
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int a , b;
    int n = A.size();
    vector<int> arr(n+1, -1);

    for(auto i : A){
        if(arr[i] == -1) arr[i] = 1;
        else a = i;
    }

    for(int i = 1; i <=n ; i++){
        if(arr[i] == -1) {b = i; break;}
    }

    return {a, b};
}

}
```
