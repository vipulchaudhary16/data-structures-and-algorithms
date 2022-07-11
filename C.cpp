#include<bits/stdc++.h>
using namespace std;

int fillCups(int a, int b, int c) {
        int sec = 0;
        cout<<a<<" "<<b<<" "<<c<<"   "<<sec<<"6\n";

        while(a != 0 and b != 0){
            sec++;
            a--;
            b--;
            cout<<a<<" "<<b<<" "<<c<<"   "<<sec<<"12\n";
        }

        if(a == 0){
            //b and c baaki h
            while(b != 0 and c != 0){
                sec++;
                b--;
                c--;
                cout<<a<<" "<<b<<" "<<c<<"   "<<sec<<"21\n";
            }
            if(b == 0){
                //sirf c baaki h
                while(c != 0){
                    sec++;
                    c--;
                    cout<<a<<" "<<b<<" "<<c<<"   "<<sec<<"28\n";
                }
                return sec;
            } else if(c == 0){
                //sirf b baaki h
                while(b != 0){
                    sec++;
                    b--;
                    cout<<a<<" "<<b<<" "<<c<<"   "<<sec<<"36\n";
                }
                return sec;
            }

            return sec;
        }

        if(b == 0){
            //a and c baaki h
            while(a != 0 and c != 0){
                sec++;
                a--;
                c--;
                cout<<a<<" "<<b<<" "<<c<<"   "<<sec<<"50\n";
            } if(a == 0){
                //sirf c baki h
                while(c != 0){
                    sec++;
                    c--;
                    cout<<a<<" "<<b<<" "<<c<<"   "<<sec<<"56\n";
                }
                return sec;
            } else if(c == 0){
                //sirf a baki h
                while(a != 0){
                    sec++;
                    a--;
                    cout<<a<<" "<<b<<" "<<c<<"   "<<sec<<"64\n";
                }
                return sec;
            }
        }
        
        
        return sec;
    }

int main()
{
    cout<<fillCups(5, 4 , 4);
    return 0;
}

