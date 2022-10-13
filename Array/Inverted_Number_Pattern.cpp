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
