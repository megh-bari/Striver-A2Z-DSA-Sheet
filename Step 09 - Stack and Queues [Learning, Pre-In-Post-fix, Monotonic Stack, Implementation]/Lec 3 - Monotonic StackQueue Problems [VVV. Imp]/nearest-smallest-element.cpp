// brute
vector<int> nextSmallerElement(vector<int> &arr, int n) {
    vector<int> nextSmallest(n, -1); 

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                nextSmallest[i] = arr[j];
                break;
            }
        }
    }
    return nextSmallest;
}


// optimal

vector<int> nextSmallerElement(vector<int> &arr, int n) {
    vector<int> nextSmallest(n, -1);
    stack<int> st;  

    for (int i = n - 1; i >= 0; i--) {  
        while (!st.empty() && st.top() >= arr[i]) {  
            st.pop();
        }
        nextSmallest[i] = st.empty() ? -1 : st.top();  
        st.push(arr[i]);  
    }

    return nextSmallest;
}