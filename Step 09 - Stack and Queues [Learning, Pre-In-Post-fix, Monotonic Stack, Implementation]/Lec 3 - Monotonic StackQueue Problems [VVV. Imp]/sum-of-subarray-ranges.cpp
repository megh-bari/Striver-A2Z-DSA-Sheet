class Solution {
    public:
        // for minimum
        // (NSE) for sum of subarray minimum
        vector<int> findNSE(vector<int>& arr) {
            int n = arr.size();
            stack<int> st;
            vector<int> nse(n, n);
            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && arr[st.top()] >= arr[i]) {
                    st.pop();
                }
                nse[i] = st.empty() ? n : st.top();
                st.push(i);
            }
            return nse;
        }
    
        // (PSE) for sum of subarray minimum
        vector<int> findPSE(vector<int>& arr) {
            int n = arr.size();
            stack<int> st;
            vector<int> pse(n, -1);
            for (int i = 0; i < n; i++) {
                while (!st.empty() && arr[st.top()] > arr[i]) {
                    st.pop();
                }
                pse[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }
            return pse;
        }
    
        // sum of subarray minimums
        int sumSubarrayMins(vector<int>& arr) {
            int n = arr.size();
            vector<int> nse = findNSE(arr);
            vector<int> pse = findPSE(arr);
            long long total = 0;
            int mod = (int)(1e9 + 7);
    
            for (int i = 0; i < n; i++) {
                long long left = i - pse[i];
                long long right = nse[i] - i;
               total = (total + (arr[i] * left % mod) * right % mod) % mod;
            }
            return (int)total;
        }
    
        // for maximum
    
        // (NGE) for sum of subarray maximum
        vector<int> findNGE(vector<int>& arr) {
            int n = arr.size();
            stack<int> st;
            vector<int> nge(n, n);
            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && arr[st.top()] <= arr[i]) {
                    st.pop();
                }
                nge[i] = st.empty() ? n : st.top();
                st.push(i);
            }
            return nge;
        }
    
        // (PGE) for sum of subarray maximum
        vector<int> findPGE(vector<int>& arr) {
            int n = arr.size();
            stack<int> st;
            vector<int> pge(n, -1);
            for (int i = 0; i < n; i++) {
                while (!st.empty() && arr[st.top()] < arr[i]) {
                    st.pop();
                }
                pge[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }
            return pge;
        }
    
        // sum of subarray maximums
        int sumSubarrayMaxs(vector<int>& arr) {
            int n = arr.size();
            vector<int> nge = findNGE(arr);
            vector<int> pge = findPGE(arr);
            long long total = 0;
            int mod = (int)(1e9 + 7);
    
            for (int i = 0; i < n; i++) {
                long long left = i - pge[i];
                long long right = nge[i] - i;
               total = (total + (arr[i] * left % mod) * right % mod) % mod;
            }
            return (int)total;
        }
    
        long long subArrayRanges(vector<int>& nums) {
           return (long long)sumSubarrayMaxs(nums) - (long long)sumSubarrayMins(nums);
        }
    };
    