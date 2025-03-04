class Solution {
    public:
        // NSE
        vector<int> nextSmallerElement(vector<int>& arr, int n) {
            vector<int> nextSmallest(n, n);
            stack<int> st;
    
            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && arr[st.top()] >= arr[i]) {
                    st.pop();
                }
                nextSmallest[i] = st.empty() ? n : st.top();
                st.push(i);
            }
            return nextSmallest;
        }
    
        // PSE
        vector<int> previousSmallerElement(vector<int>& arr) {
            int n = arr.size();
            stack<int> st;
            vector<int> pse(n, -1);
    
            for (int i = 0; i < n; i++) {
                while (!st.empty() && arr[st.top()] >= arr[i]) {
                    st.pop();
                }
                pse[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }
            return pse;
        }
    
        // Histogram
        int largestRectangleArea(vector<int>& heights) {
            int n = heights.size();
            vector<int> pse = previousSmallerElement(heights);
            vector<int> nse = nextSmallerElement(heights, n);
    
            int maxArea = 0;
            for (int i = 0; i < n; i++) {
                int width = nse[i] - pse[i] - 1;
                maxArea = max(maxArea, heights[i] * width);
            }
    
            return maxArea;
        }
    
       
        int maximalRectangle(vector<vector<char>>& matrix) {
            if (matrix.empty()) return 0;  
            int n = matrix.size();
            int m = matrix[0].size();
    
            // prefix sum
            vector<vector<int>> prefixSum(n, vector<int>(m, 0)); 
            int maxArea = 0;
    
        
            for (int j = 0; j < m; j++) {
                int sum = 0;
                for (int i = 0; i < n; i++) {
                    sum = (matrix[i][j] == '0') ? 0 : sum + (matrix[i][j] - '0');
                    prefixSum[i][j] = sum;
                }
            }
    
           
            for (int i = 0; i < n; i++) {
                maxArea = max(maxArea, largestRectangleArea(prefixSum[i]));
            }
    
            return maxArea;
        }
    };
    