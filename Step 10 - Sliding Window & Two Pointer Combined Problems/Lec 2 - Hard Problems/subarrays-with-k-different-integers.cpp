// brute: generate all subarrays

class Solution {
    public:
        int subarraysWithKDistinct(vector<int>& nums, int k) {
            int n = nums.size();
            int cnt = 0;
    
            for (int i = 0; i < n; i++) {
                map<int, int> mpp;
                for (int j = i; j < n; j++) {
                    mpp[nums[j]]++;
                    if (mpp.size() == k) {
                        cnt += 1;
                    } else if (mpp.size() > k)
                        break;
                }
            }
            return cnt;
        }
    };

// optimal:

class Solution {
    public:
        int ans(vector<int>& nums, int k) {
            int n = nums.size();
            int l = 0;
            int r = 0;
            int cnt = 0;
            unordered_map<int, int>mpp;
    
            if (k == 0) return 0;
    
            while(r<n){
                mpp[nums[r]]++;
    
                while(mpp.size()>k){
                    mpp[nums[l]]--;
                    if(mpp[nums[l]]==0){
                          mpp.erase(nums[l]);
                    }
                    l++;
                }
                cnt+=(r-l+1);
                r++;
            }
            return cnt;
        }
        int subarraysWithKDistinct(vector<int>& nums, int k) {
            return ans(nums,k) - ans(nums,k-1);
        }
    };