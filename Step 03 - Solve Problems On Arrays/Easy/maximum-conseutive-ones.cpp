#include<bits/stdc++.h>

using namespace std;

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int maxi = 0; 
    int cnt = 0; 

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            cnt++; 
            maxi = (maxi > cnt) ? maxi : cnt; 
        } else {
            cnt = 0; 
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

    cout<<"number of consecutive ones: "<<findMaxConsecutiveOnes(arr,n);


    return 0;
}