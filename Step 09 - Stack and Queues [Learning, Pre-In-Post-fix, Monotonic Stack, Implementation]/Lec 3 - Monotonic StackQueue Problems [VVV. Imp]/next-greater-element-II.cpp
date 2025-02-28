class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            vector<int> nextGreater(nums.size(), -1); //Size of nums and  All elements are initialized to -1
            stack<int> st;
            int n = nums.size();
            
            for(int i=2*n-1; i>=0; i--) {
                while (!st.empty() && st.top() <= nums[i % n]) {
                    st.pop();
                }
                if (i < n) {
                    nextGreater[i] = st.empty() ? -1 : st.top();
                }
                st.push(nums[i % n]);
            }
            
            return nextGreater;
        }
    };
    