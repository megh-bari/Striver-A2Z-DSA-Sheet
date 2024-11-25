#include <bits/stdc++.h>
using namespace std;

int longSubArrWithSumK(int arr[], int n, long long k) {
   map<long long, int> prefixSumMap; 
    long long sum = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == k) {
            maxLength = i + 1;
        }

        if (prefixSumMap.find(sum - k) != prefixSumMap.end()) {
            maxLength = max(maxLength, i - prefixSumMap[sum - k]);
        }

        if (prefixSumMap.find(sum) == prefixSumMap.end()) {
            prefixSumMap[sum] = i;
        }
    }

    return maxLength;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longSubArrWithSumK(arr, n, k) << endl;
    return 0;
}
