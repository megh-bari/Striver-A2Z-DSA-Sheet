class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            int n = coins.size();
            int count = 0;
            int remaining = amount;
    
            if(amount==0) return 0;
    
            sort(coins.rbegin(), coins.rend());
    
            for(int i=0; i<n; i++){
                if(coins[i]<=remaining){
                    count+= remaining / coins[i];
                    remaining%=coins[i];
                }
            }
            return (remaining == 0) ? count : -1;
        }
    };

// Note: This solution is not optimal and does not pass all test cases. This problem is based on Dynamic Programming (DP), mentioned in the Striver A2Z Sheet. I tried to solve it using Greedy, but it does not always provide the correct answer.