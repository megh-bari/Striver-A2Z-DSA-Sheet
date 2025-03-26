// brute:
class Solution {
    public:
        int numberOfSubstrings(string s) {
            int n = s.size();
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                vector<int> hash(3, 0);
                for (int j = i; j < n; j++) {
                    hash[s[j] - 'a'] = 1;
                    if (hash[0] + hash[1] + hash[2] == 3) {
                        cnt++;
                    }
                }
            }
            return cnt;
        }
    };

    // optimal
    class Solution {
        public:
            int numberOfSubstrings(string s) {
                int n = s.size();
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    vector<int> hash(3, 0);
                    for (int j = i; j < n; j++) {
                        hash[s[j] - 'a'] = 1;
                        if (hash[0] + hash[1] + hash[2] == 3) {
                            cnt+=(n-j);
                            break;
                        }
                    }
                }
                return cnt;
            }
        };