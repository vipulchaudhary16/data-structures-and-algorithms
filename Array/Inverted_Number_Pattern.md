# [Inverted Number Pattern](https://github.com/Nitin-GH/Coding-ninjas/blob/master/Lecture%205%20Patterns%202/Inverted%20Number%20Pattern)

```cpp
#include<iostream>
using namespace std;
int main(){
  int n , i=1, j;
    cin>>n;
    int val = n;
    while(i<=n){
        j=1;
        while(j<=n-i+1){
            cout<<val;
            j++;
        }
        val--;
        cout<<endl;
        i++;
    }
}
