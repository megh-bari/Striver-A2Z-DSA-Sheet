#include <bits/stdc++.h>

using namespace std;

// brute force

pair<int,int> twoSum(int arr[], int n, int target){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]+arr[j]==target){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

// better approach 

pair<int, int> twoSumBetterWay(int arr[], int n, int target) {
    map<int, int> mpp; 
    for (int i = 0; i < n; i++) {
        int a = arr[i];
        int more = target - a;
        if (mpp.find(more) != mpp.end()) {
            return {mpp[more], i};
        }
        mpp[a] = i; 
    }
    return {-1, -1}; 
}

// slightly better

string twoSumBetter(vector<int>arr, int n, int target){
    int left=0, right =n-1;
    sort(arr.begin(), arr.end());

    while (left<right)
    {
        int sum = arr[left]+arr[right];
        if(sum==target){
            return "Yes";
        }else if(sum<target) left++;
        else left--;
      
    }
    return "No";
    
}

int main()
{
    int n;
    cin >> n;
    int target;
    cin >> target;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // ***brute way***

    // pair<int,int> result = twoSum( arr, n, target);

    // if(result.first==-1){
    //     cout<<"no result found"<<endl;
    // }else{
    //     cout<<"indices: "<<result.first<<" "<<result.second<<endl;
    // }

    // ***Better Way***

    pair<int,int>betterWayResult=twoSumBetterWay(arr,n,target);

    if(betterWayResult.first==-1){
        cout<<"no result found!";
    }else{
        cout<<"indices: "<<betterWayResult.first<<" "<<betterWayResult.second<<endl;
    }


    return 0;
}