#include <bits/stdc++.h>

using namespace std;


//  brute 
int singleNumber(int arr[], int n)
{
    int maxi = arr[0];
    for(int i=0; i<n; i++){
        maxi = max(maxi, arr[i]);
       int hash[maxi]={0};

       for(int i=0; i<n; i++){
        hash[arr[i]]++;
       }
       for(int i=0; i<n; i++){
        if(hash[arr[i]]==1){
            return arr[i];
        }
       }
    }
}


// better

int singleNum(int arr[],int n){
    map<int, int>mpp;
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
    }
    for(auto it: mpp){
        if(it.second==1){
            return it.first;
        }
    }

}


// optimal

int singleNumberAppear(int arr[], int n){
    int result =0;
    for(int i=0; i<n; i++){
        result^=arr[i];
    }
    return result;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // cout << "Single Number Appears: " << singleNumber(arr, n);
    // cout << "Single Number Appears: " << singleNum(arr, n);
    cout << "Single Number Appears: " << singleNumberAppear(arr, n);
    return 0;
}