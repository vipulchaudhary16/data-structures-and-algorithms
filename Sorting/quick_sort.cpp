#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;

    while (i < j)
    {
        do
        {
            i++;
            //jab tak pivot se bada element na mile tab tak i++ karo
        } while (arr[i] <= pivot);

        do
        {
            j--;
            //jab tak pivot se chhota element na mile tab tak j--
        } while (arr[j] > pivot);

        if (i < j)
            //agar mil jaaye to swap kar do
            swap(&arr[i], &arr[j]);
    }

    //ab pivot ko swap karo
    swap(&arr[low], &arr[j]);

    //pivot index return karo
    return j;
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int j = partition(arr, low, high);
        quick_sort(arr, low, j);
        quick_sort(arr, j + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    quick_sort(A, 0, n );
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}