#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr) {
  int n = arr.size();
  int low = 0, high = n - 1;
  int ans = INT_MAX;
  int index = -1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[low] <= arr[mid]) {
      if (arr[low] < ans) {
        ans = arr[low];
        index = low;
      }
      low = mid + 1;
    } else {
      if (arr[mid] < ans) {
        ans = arr[mid];
        index = mid;
      }
      high = mid - 1;
    }
  }
  return index;
}