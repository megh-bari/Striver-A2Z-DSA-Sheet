// brute

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
   int n = s.size();
        int maxLen = -1;
        unordered_map<char, int> mpp;

        for (int i = 0; i < n; i++) {
            mpp.clear();
            for (int j = i; j < n; j++) {
                mpp[s[j]]++; 
                
                if (mpp.size() == k) {
                    maxLen = max(maxLen, j - i + 1);
                } else if (mpp.size() > k) {
                    break; 
                }
            }
        }
        return maxLen;
    }
};

// optimal

class Solution {
    public:
      int longestKSubstr(string &s, int k) {
     int n = s.size();
          int maxLen = -1;
          unordered_map<char, int> mpp;
          int l=0, r=0;
          
          while(r<n){
              mpp[s[r]]++;
              
              while(mpp.size()>k){
                  mpp[s[l]]--;
                  if(mpp[s[l]]==0) {
                      mpp.erase(s[l]);
                  }
                  l++;
              }
               if (mpp.size() ==k) {
              maxLen = max(maxLen, r-l + 1);
          }
          r++;
          }
          return maxLen;
      }
  };