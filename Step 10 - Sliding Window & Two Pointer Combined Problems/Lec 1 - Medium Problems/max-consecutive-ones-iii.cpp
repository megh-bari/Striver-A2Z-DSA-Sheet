// brute:
class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int n = nums.size();
            int maxLen = 0;
    
            for (int i = 0; i < n; i++) {
                int zeros=0;
                for (int j = i; j < n; j++) {
                    if (nums[j] == 0) {
                        zeros++;
                    }
                    if (zeros <= k) {
                        int len = j - i + 1;
                        maxLen = max(len, maxLen);
                    } else
                        break;
                }
            }
            return maxLen;
        }
    };

// optimal:
class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int n = nums.size();
            int maxLen = 0;
            int l = 0;
            int zeros = 0;
    
            for (int r = 0; r < n; ++r) {
                if (nums[r] == 0)
                    zeros++;
    
                while (zeros > k) {
                    if (nums[l] == 0)
                        zeros--;
                    l++;
                }
    
                maxLen = max(maxLen, r - l + 1);
            }
    
            return maxLen;
        }
    };
    
// most optimal: lil minor change
class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int n = nums.size();
            int maxLen = 0;
            int l = 0;
            int zeros = 0;
    
            for (int r = 0; r < n; ++r) {
                if (nums[r] == 0)
                    zeros++;
    
                if (zeros > k) {
                    if (nums[l] == 0)
                        zeros--;
                    l++;
                }
                if (zeros <= k) {
                    maxLen = max(maxLen, r - l + 1);
                }
            }
    
            return maxLen;
        }
    };
    