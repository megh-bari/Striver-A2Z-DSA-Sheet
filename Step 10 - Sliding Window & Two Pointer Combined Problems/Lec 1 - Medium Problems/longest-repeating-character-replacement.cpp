// brute
class Solution {
    public:
        int characterReplacement(string s, int k) {
            int n = s.size();
            int maxLen = 0;
            int maxFreq = 0;
            for (int i = 0; i < n; i++) {
                vector<int> hash(26, 0);
                for (int j = i; j < n; j++) {
                    hash[s[j] - 'A']++;
                    maxFreq = max(maxFreq, hash[s[j] - 'A']);
                    int length = j - i + 1;
                    int change = length - maxFreq;
    
                    if (change <= k) {
                        maxLen = max(maxLen, length);
                    } else
                        break;
                }
            }
            return maxLen;
        }
    };

// optimal
class Solution {
    public:
        int characterReplacement(string s, int k) {
            int n = s.size();
            int maxLen = 0;
            int maxFreq = 0;
            int l = 0, r = 0;
            vector<int> hash(26, 0);
    
            while (r < n) {
                hash[s[r] - 'A']++;
                maxFreq = max(maxFreq, hash[s[r] - 'A']);
    
                int length = r - l + 1;
    
                if (length - maxFreq > k) {
                    hash[s[l] - 'A']--;
                    l++;
                }
    
                maxLen = max(maxLen, r - l + 1);
    
                r++;
            }
    
            return maxLen;
        }
    };
    