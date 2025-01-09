#include<bits/stdc++.h>

using namespace std;

// brute

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==target){
                    return true;
                }
            }
        }
        return false;
    }


// better:

    int bs(vector<int>& nums, int target) {
        int left = 0, high = nums.size() - 1;

        while (left <= high) {
            int mid = left + (high - left) / 2;

            if (nums[mid] == target)
                return true;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                high = mid - 1;
        }

        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++){
            if(matrix[i][0]<=target && target<= matrix[i][m-1]){
               if (bs(matrix[i], target)) {
                return true;
            }
            }
        }
        return false;
    }


// optimal: BS 

bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int n = matrix.size(); 
        int m = matrix[0].size();

        int low = 0, high = n * m - 1; 

        while (low <= high) {
            int mid = low + (high - low) / 2; 
            int row = mid / m; 
            int col = mid % m; 

            if (matrix[row][col] == target) {
                return true;
            } 
           
            else if (matrix[row][col] < target) {
                low = mid + 1;
            } 
           
            else {
                high = mid - 1;
            }
        }

        return false; 
    }
