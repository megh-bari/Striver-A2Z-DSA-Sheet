#include <bits/stdc++.h>

using namespace std;

//* optimal using lb and ub

// lower bound

int lowerBound(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

// upperbound

int upperBound(vector<int> &arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int lb = lowerBound(arr, n, k);
    int ub = upperBound(arr, n, k);

    if (lb == n || arr[lb] != k)
        return {-1, -1};
    return {lb, ub - 1};
}


//* plain code

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
