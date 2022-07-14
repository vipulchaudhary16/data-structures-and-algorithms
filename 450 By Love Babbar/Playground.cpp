#include<bits/stdc++.h>
using namespace std;

void move_minus_at_begining(int arr[], int n){
        int j = 0;
        for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            // if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main()
{
    int arr[] = {-1,3,-8,0,6};
    int size = sizeof(arr) / sizeof(arr[0]);

    move_minus_at_begining(arr,  size );

    for(int i = 0; i < size; i++)
        cout<<arr[i]<<" ";

    return 0;
}