#include <bits/stdc++.h>
using namespace std;

void find_largest(int arr[], int n){
    int largest = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    cout<<largest<<endl;
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    find_largest(arr, n); 
    return 0;
}
