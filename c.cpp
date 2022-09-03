#include<bits/stdc++.h>
using namespace std;

int main()
{
    int r, m;
    cout<<"Enter value of r and m : ";
    cin>>r>>m;

    int mod = r%m;
    for(int i = 0; i < 50; i++){
        if(i%m == mod){
            cout<<i<<" ";
        }
        if( (m - (i%m)) == mod){
            cout<<-i<<" ";
        }
    }
    return 0;
}