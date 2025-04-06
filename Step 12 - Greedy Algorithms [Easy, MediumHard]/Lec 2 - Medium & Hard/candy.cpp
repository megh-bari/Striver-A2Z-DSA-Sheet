// brute
class Solution {
    public:
        int candy(vector<int>& ratings) {
            int n = ratings.size();
            vector<int> left(n, 1);
            vector<int> right(n, 1);
    
            // Left to right
            for (int i = 1; i < n; i++) {
                if (ratings[i] > ratings[i - 1]) {
                    left[i] = left[i - 1] + 1;
                }
            }
    
            // Right to left
            for (int i = n - 2; i >= 0; i--) {
                if (ratings[i] > ratings[i + 1]) {
                    right[i] = right[i + 1] + 1;
                }
            }
    
            // Combine both
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += max(left[i], right[i]);
            }
            return sum;
        }
    };

// lil optimal

class Solution {
    public:
        int candy(vector<int>& ratings) {
            int n = ratings.size();
            vector<int> left(n, 1);
    
            // Left to right
            for (int i = 1; i < n; i++) {
                if (ratings[i] > ratings[i - 1]) {
                    left[i] = left[i - 1] + 1;
                }
            }
    
            // right to left on fly
            int right = 1, sum = left[n - 1];
            for (int i = n - 2; i >= 0; i--) {
                if (ratings[i] > ratings[i + 1]) {
                    right += 1;
                } else {
                    right = 1;
                }
                sum += max(left[i], right);
            }
    
            return sum;
        }
    };

    
// most optimal
class Solution {
    public:
        int candy(vector<int>& ratings) {
            int n = ratings.size();
            int sum = 1;
            int i = 1;
    
            while (i < n) {
                if (ratings[i] == ratings[i - 1]) {
                    sum += 1;
                    i++;
                    continue;
                }
    
                // Increasing slope
                int peak = 1;
                while (i < n && ratings[i] > ratings[i - 1]) {
                    peak++;
                    sum += peak;
                    i++;
                }
    
                // Decreasing slope
                int down = 0;
                while (i < n && ratings[i] < ratings[i - 1]) {
                    down++;
                    sum += down;
                    i++;
                }
    
                if (down >= peak) {
                    sum += down - peak + 1;
                }
            }
    
            return sum;
        }
    };
    