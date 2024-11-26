#include <bits/stdc++.h>
using namespace std;

int longSubArrWithSumK(vector<int>& arr, int n, long long k) {
    int left = 0, right = 0;
    long long sum = arr[0];
    int maxLen = 0;

    while (right < n) {
        while (left <= right && sum > k) {
            sum -= arr[left];
            left++;
        }
        
    
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        
       
        right++;
        if (right < n) sum += arr[right];  
    }
    
    return maxLen;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longSubArrWithSumK(arr, n, k) << endl;
    return 0;
}
