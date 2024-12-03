#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArrayBySign(int arr[], int n) {
    vector<int> ans(n, 0);
    int posIndex = 0, negIndex = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            ans[negIndex] = arr[i];
            negIndex += 2;
        } else {
            ans[posIndex] = arr[i];
            posIndex += 2;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = rearrangeArrayBySign(arr, n);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
