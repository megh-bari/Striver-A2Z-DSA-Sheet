class Solution {
    public:
        int answer(vector<int>& nums, int goal) {
            int l = 0, r = 0;
            int count = 0;
            int sum = 0;
            int n = nums.size();
            if (goal < 0)
                return 0;
    
           for (int r = 0; r < n; r++) {
                sum += nums[r];
    
                while (sum > goal) { 
                    sum -= nums[l];
                    l++;
                }
    
                count += (r - l + 1); 
            }
            return count;
        }
    
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            return answer(nums, goal) - answer(nums, goal - 1);
        }
    };