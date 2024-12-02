#include<bits/stdc++.h>

using namespace std;

//  better approach
int maxSubarray(int arr[], int n){
    int maxi = INT64_MIN;
    for(int i=0; i<n; i++){
        int sum =0;
        for(int j=i; j<n; j++){
            sum+=arr[j];
            maxi = max(sum, maxi);
        }
    }

}


int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<maxSubarray(arr,n);

    return 0;
}