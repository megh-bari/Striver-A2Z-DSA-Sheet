// brute:
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int n = s.length();
            int maxLen = 0;
            unordered_map<char, bool> hash;
    
            for (int i = 0; i < n; i++) {
                hash.clear();
                for (int j = i; j < n; j++) {
                    if (hash[s[j]]) break; 
                    int length = j - i + 1;
                    maxLen = max(length, maxLen);
                    hash[s[j]] = true; 
                }
            }
            return maxLen;
        }
    };

// optimal:
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int n = s.length();
            int maxLen = 0;
            vector<int> hash(256, -1);
            int l = 0, r = 0;
    
            while (r < n) {
                if (hash[s[r]] != -1) {
                    if (hash[s[r]] >= l) {
                        l = hash[s[r]] + 1;
                    }
                }
                int len = r - l + 1;
                maxLen = max(len, maxLen);
                hash[s[r]] = r;
                r++;
            }
            return maxLen;
        }
    };
    