#include <bits/stdc++.h>

using namespace std;

// selection sort
void selection_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int min = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}


// bubble sort 

void bubble_sort(int arr[], int n){
    for(int i=n-1; i>=0; i--){
        int did_Swap = 0;
        for(int j = 0; j<=i-1; j++){
            if(arr[j]>arr[j+1]){
                    int temp = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = temp;
                    did_Swap = 1;
            }
        }
        if(did_Swap==0) break;
        cout<<"runs\n";
    }
}

// insertion sort

void insertion_sort(int arr[], int n){
    for(int i=0; i<=n-1;i++){
        int j = i;
        while (j>0 && arr[j-1]>arr[j])
        {
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j]= temp;
            j--;
            cout<<"runs";
        }
        
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i <= n; i++)
        cin >> arr[i];
    // selection_sort(arr, n);

    // bubble_sort(arr,n);

    insertion_sort(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}