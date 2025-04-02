// brute

class Solution {
    public:
        bool checkValidString(string s) {
            return checkValidStringHelper(s, 0, 0);
        }
    
    private:
        bool checkValidStringHelper(string& s, int ind, int cnt) {
            if (cnt < 0) return false;  
            if (ind == s.size()) return cnt == 0;  
            if (s[ind] == '(') 
                return checkValidStringHelper(s, ind + 1, cnt + 1);
            if (s[ind] == ')') 
                return checkValidStringHelper(s, ind + 1, cnt - 1);
            
            // If '*', it can be '(', ')' or empty
            return checkValidStringHelper(s, ind + 1, cnt + 1) ||
                   checkValidStringHelper(s, ind + 1, cnt - 1) ||
                   checkValidStringHelper(s, ind + 1, cnt);
        }
    };

    
// this is brute force and it'll hit TLE, so for that we have to used DP, will do later in DP playlist