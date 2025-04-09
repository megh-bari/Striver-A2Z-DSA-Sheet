class Solution {
    public:
        static bool comp(const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // sort by end time
        }
    
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            int n = intervals.size();
            if (n == 0)
                return 0;
    
            sort(intervals.begin(), intervals.end(), comp);
            int cnt = 1;
            int lastEndTime = intervals[0][1]; // last interval time
    
            for(int i=0; i<n; i++){
                if(intervals[i][0]>=lastEndTime){
                    cnt++;
                    lastEndTime = intervals[i][1];
                }
            }
            return n-cnt;
        }
    };