#include <bits/stdc++.h>

// first occurance

int firstOccurance(vector<int> arr, int n, int x) {
  int low = 0, high = n - 1;
  int first = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == x) {
      first = mid;
      high = mid - 1;
    } else if(arr[mid]<x){
        low = mid + 1;
    }else{
        high = mid - 1;
    }
  }
  return first;
}

// last occurance

int lastOccurance(vector<int> &arr, int n, int x) {
  int low = 0, high = n - 1;
  int last = -1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == x) {
      last = mid;
      low = mid + 1;
    } else if(arr[mid]<x){
      low = mid + 1;
    }else{
        high = mid - 1;
    }
  }
  return last;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k) {
  int first = firstOccurance(arr, n, k);
  if(first==-1) return {-1,-1};
  int last = lastOccurance(arr,n,k);
  return {first, last};
}


int count(vector<int>& arr, int n, int x) {
	pair<int, int> ans = firstAndLastPosition(arr, n, x);
	if(ans.first==-1) return 0;
	return ans.second - ans.first+1;
}
