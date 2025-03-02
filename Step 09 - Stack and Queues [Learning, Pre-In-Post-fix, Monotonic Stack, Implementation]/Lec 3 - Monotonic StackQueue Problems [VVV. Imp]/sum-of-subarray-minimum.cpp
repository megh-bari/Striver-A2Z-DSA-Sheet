// brute
class Solution {
    public:
        int sumSubarrayMins(vector<int>& arr) {
            int n = arr.size();
            int sum = 0;
            int mod =(int)(1e9 + 7);
    
            for(int i=0; i<n; i++){
                int mini = arr[i];
                for (int j = i; j < n; j++) {
                    mini = min(mini, arr[j]);  
                    sum = (sum + mini) % mod; 
                }
    
            }
                return sum;
        }
    };

// optimal 
class Solution {
    public:
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
    
        int sumSubarrayMins(vector<int>& arr) {
            int n = arr.size();
            vector<int> nse = findNSE(arr);
            vector<int> pse = findPSE(arr);
            long long total = 0;
            int mod = (int)(1e9 + 7);
            
            for (int i = 0; i < n; i++) {
                long long left = i - pse[i];
                long long right = nse[i] - i;
                total = (total + arr[i] * left * right) % mod;
            }
            return (int)total;
        }
    };
    