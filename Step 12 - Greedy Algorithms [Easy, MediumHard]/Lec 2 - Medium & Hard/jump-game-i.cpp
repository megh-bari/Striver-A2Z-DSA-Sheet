class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int n = nums.size();
            int maxLen = 0;
            for(int i=0; i<n; i++){
                if(i>maxLen) return false;
                maxLen = max(maxLen, i+nums[i]);
                if(maxLen>=n) break;
            }
            return true;
        }
    };