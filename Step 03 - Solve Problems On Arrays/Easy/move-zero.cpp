#include<bits/stdc++.h>

using namespace std;
void moveZero(int arr[], int n) {
    int nonZeroIndex = 0; 

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[nonZeroIndex] = arr[i];
            if (i != nonZeroIndex) {
                arr[i] = 0;  
            }
            nonZeroIndex++;
        }
    }
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
moveZero(arr,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}