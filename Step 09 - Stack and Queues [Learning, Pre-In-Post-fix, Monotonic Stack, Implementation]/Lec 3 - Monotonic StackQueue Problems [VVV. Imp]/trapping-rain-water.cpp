// not much optimal 
class Solution {
    public:
        vector<int> prefixMax(vector<int>& arr) {
            int n = arr.size();
            vector<int> prefix(n);
            prefix[0] = arr[0];
            for (int i = 1; i < n; i++) {
                prefix[i] = max(prefix[i - 1], arr[i]);
            }
    
            return prefix;
        }
    
        vector<int> suffixMax(vector<int>& arr) {
            int n = arr.size();
            vector<int> suffix(n);
            suffix[n - 1] = arr[n - 1];
    
            for (int i = n - 2; i >= 0; i--) {
                suffix[i] = max(suffix[i + 1], arr[i]);
            }
    
            return suffix;
        }
        int trap(vector<int>& height) {
            int total = 0;
            int n = height.size();
            if (n == 0)
                return 0;
            vector<int> leftMax = prefixMax(height);
            vector<int> rightMax = suffixMax(height);
    
            for (int i = 0; i < n; i++) {
    
                if (height[i] < leftMax[i] && height[i] < rightMax[i]) {
                    total += min(leftMax[i], rightMax[i]) - height[i];
                }
            }
            return total;
        }
    };

// optimal 
class Solution {
    public:
        int trap(vector<int>& height) {
            if (height.empty()) return 0;  
            
            int total = 0;
            int l = 0, r = height.size() - 1; 
            int lMax = 0, rMax = 0;  
            
            while (l < r) {
                if (height[l] <= height[r]) {
                    if (height[l] >= lMax) 
                        lMax = height[l];
                    else 
                        total += lMax - height[l];
                    l++;  
                } else {
                    if (height[r] >= rMax) 
                        rMax = height[r];
                    else 
                        total += rMax - height[r];
                    r--;  
                }
            }
            
            return total;
        }
    };
    