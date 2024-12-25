#include <bits/stdc++.h>

using namespace std;

// iterative

int search(vector<int> &nums, int target)
{
    int left = 0, high = nums.size() - 1;

    while (left <= high)
    {
        int mid = left + (high - left) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// recursive

int bs(vector<int>&nums, int low, int high, int target){
    if(low>high) return -1;
    int mid = (low+high)/2;

    if(nums[mid]==target) return mid;
    else if(target>nums[mid]) return bs(nums, mid+1,high, target);
    return bs(nums, low, high-1, target);
}

int search(vector<int> &nums, int target)
{
    return bs(nums, 0, nums.size()-1, target);
}