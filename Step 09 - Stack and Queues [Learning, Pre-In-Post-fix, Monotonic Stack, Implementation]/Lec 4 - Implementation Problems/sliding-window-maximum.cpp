// brute
class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            vector<int> ans;
            int n = nums.size();
            if (n == 0)
                return ans;
            for (int i = 0; i <= n - k; i++) {
                int maxi = nums[i];
                for (int j = i + 1; j < i + k; j++) {
                    maxi = max(maxi, nums[j]);
                }
                ans.push_back(maxi);
            }
            return ans;
        }
    };

// optimal

class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            vector<int> ans;
            deque<int> dq;
            int n = nums.size();
            if (n == 0)
                return ans;
    
            for (int i = 0; i < n; i++) {
                if (!dq.empty() && dq.front() == i - k)
                    dq.pop_front();
    
                while (!dq.empty() && nums[dq.back()] <= nums[i])
                    dq.pop_back();
    
                dq.push_back(i);
    
                if (i >= k - 1)
                    ans.push_back(nums[dq.front()]);
            }
            return ans;
        }
    };