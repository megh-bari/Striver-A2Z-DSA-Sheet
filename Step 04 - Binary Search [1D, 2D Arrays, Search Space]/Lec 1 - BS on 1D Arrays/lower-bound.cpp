#include<bits/stdc++.h>

using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
  int low = 0, high = n - 1;
  int ans = n;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] >= x) {
      ans = mid;
      high = mid - 1; 
    }
    else {
      low = mid + 1;
    }
  }
  return ans;
}

// using c++ stl

#include <bits/stdc++.h>
int lowerBound(std::vector<int>& arr, int n, int x) {
  auto lb = std::lower_bound(arr.begin(), arr.end(), x);
  return lb - arr.begin();  
}
