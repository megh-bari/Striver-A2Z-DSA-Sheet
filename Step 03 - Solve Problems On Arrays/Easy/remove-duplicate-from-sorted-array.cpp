#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(int arr[], int n) {
    set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(arr[i]);
    }

    int k = st.size();
    int j = 0;
    for (int x : st) {
        arr[j++] = x;
    }
    return k;
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int newSize = removeDuplicates(arr, n);

    for (int i = 0; i < newSize; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
