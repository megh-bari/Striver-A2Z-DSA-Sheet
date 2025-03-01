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