#include<bits/stdc++.h>

using namespace std;

bool searchInARotatedSortedArrayII(vector<int>&A, int key) {
    int n = A.size();
    int low = 0, high = n - 1;

    while(low<=high){
        int mid = low + (high - low)/2;

        if(A[mid]==key) return true;
            if(A[low]==A[mid] && A[mid]==A[high]){
                low++, high--;
                continue;
            }

        // check for left sorted array
        if(A[low]<=A[mid]){
            if(A[low]<=key && key<=A[mid])
                high = mid - 1;
            else 
                low = mid + 1;
        }

        // check for right sorted array
        else{
            if(A[mid]<=key && key<=A[high])
                low = low + 1;
            else
                high = mid - 1;
        }
    }
    return false;
}
