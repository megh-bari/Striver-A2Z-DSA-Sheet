// brute
class Solution {
    public:
        int jump(vector<int>& nums) {
            int n = nums.size();
            if (n == 1)
                return 0;
            if (nums[0] >= n - 1)
                return 1;
            int mini = INT_MAX;
            for (int i = 1; i < nums[i]; i++) {
                vector<int> subNums(nums.begin() + i, nums.end());
                mini = min(mini, 1 + jump(subNums));
            }
            return mini;
        }
    };

// optimal: greedy

class Solution {
    public:
        int jump(vector<int>& nums) {
            int n = nums.size();
            if (n == 1) return 0;
             int jumps = 0, currEnd = 0, farthest = 0;
    
             for(int i=0; i<=n-1; i++){
                farthest = max(farthest, i+nums[i]);
                if(i==currEnd){
                    jumps++;
                    currEnd=farthest;
                }
    
                if(currEnd>=n-1) break;
             }
             return jumps;
        }
    };