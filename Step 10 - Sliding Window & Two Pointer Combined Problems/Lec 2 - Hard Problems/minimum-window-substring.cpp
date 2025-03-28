class Solution {
    public:
        string minWindow(string s, string t) {
            if (t.size() > s.size()) return "";
    
            vector<int> hash(256, 0);
            for (char c : t) hash[c]++; 
    
            int l = 0, r = 0, minLen = INT_MAX, startIdx = -1;
            int cnt = 0, required = t.size();
    
            while (r < s.size()) {
                if (hash[s[r]] > 0) cnt++;
                hash[s[r]]--;
    
                while (cnt == required) { // possible answer
                    if (r - l + 1 < minLen) {
                        minLen = r - l + 1;
                        startIdx = l;
                    }
    
                    hash[s[l]]++;
                    if (hash[s[l]] > 0) cnt--;
                    l++; 
                }
                r++; 
            }
    
            return startIdx == -1 ? "" : s.substr(startIdx, minLen);
        }
    };
    