// brute:
class Solution {
    public:
        int totalFruit(vector<int>& fruits) {
            int n = fruits.size();
            int maxLen = 0;
            for (int i = 0; i < n; i++) {
                set<int> st;
                for (int j = i; j < n; j++) {
                    st.insert(fruits[j]);
                    if(st.size()<=2){
                        maxLen = max(maxLen, j-i+1);
                    }else break;
                }
            }
            return maxLen;
        }
    };

// optimal:
class Solution {
    public:
        int totalFruit(vector<int>& fruits) {
            int n = fruits.size();
            int maxLen = 0;
            map<int, int> mpp;
            int r = 0, l = 0;
    
            while (r < n) {
                mpp[fruits[r]]++;
    
                if (mpp.size() > 2) {
                    mpp[fruits[l]]--;
                    if (mpp[fruits[l]] == 0) {
                        mpp.erase(fruits[l]);
                    }
                    l++;
                }
    
                if (mpp.size() <= 2) {
                    maxLen = max(maxLen, r - l + 1);
                }
                r++;
            }
            return maxLen;
        }
    };