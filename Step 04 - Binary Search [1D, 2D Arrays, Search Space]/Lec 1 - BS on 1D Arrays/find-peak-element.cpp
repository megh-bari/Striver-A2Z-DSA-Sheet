#include<bits/stdc++.h>
using namespace std;

  int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n-2;
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;

        while(low<=high){
            int mid = low + (high - low)/2;

            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }else if(nums[mid]>nums[mid-1]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return -1;
    }