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

// optimal

int maxSubArray(int arr[], int n){
    int sum=0, maxi=INT_MIN;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        maxi = max(sum, maxi);
        if(sum<0){
            sum=0;
        }
    }
    return maxi;
}

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    // cout<<maxSubarray(arr,n);
    
    // better soln 
    cout<<maxSubArray(arr,n);

    return 0;
}