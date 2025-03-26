class Solution {
public:
    int answer(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int count = 0;

        if (k < 0)
            return 0;

        // odd numbers
        for (int r = 0; r < n; r++) {
            if (nums[r] % 2 == 1) {
                k--;
            }

            while (k < 0) {
                if (nums[l] % 2 == 1) {
                    k++;
                }
                l++;
            }

            count += (r - l + 1);
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return answer(nums, k) - answer(nums, k - 1);
    }
};
