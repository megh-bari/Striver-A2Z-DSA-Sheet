class Solution {
    public:
        int maxScore(vector<int>& cardPoints, int k) {
            int lSum = 0;
            int rSum = 0;
            int maxSum = 0;
            int n = cardPoints.size();
    
            for (int i = 0; i < k; i++) {
                lSum += cardPoints[i];
            }
    
            maxSum = lSum;
            int rInd = n - 1;
            for (int i = k - 1; i >= 0; i--) {
                lSum -= cardPoints[i];
                rSum += cardPoints[rInd];
                rInd--;
    
                maxSum = max(maxSum, lSum + rSum);
            }
    
            return maxSum;
        }
    };
    