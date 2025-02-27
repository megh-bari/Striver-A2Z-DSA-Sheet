class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            stack<int> st;
            unordered_map<int, int> nextGreater;
            int n1 = nums1.size();
            int n2 = nums2.size();
    
            for (int i = n2 - 1; i >= 0; --i) {
                while (!st.empty() && st.top() <= nums2[i]) {
                    st.pop();
                }
                nextGreater[nums2[i]] = st.empty() ? -1 : st.top();
    
                st.push(nums2[i]);
            }
            vector<int> result(n1);
            for (int i = 0; i < n1; ++i) {
                result[i] = nextGreater[nums1[i]];
            }
    
            return result;
        }
    };