class Solution {
  public:
    
    struct Data{
    int start;
    int end;
};
       // comparitor func
        static bool comp(Data val1, Data val2) {
        return val1.end < val2.end;
    }

    int maxMeetings(vector<int>& start, vector<int>& end) {
    int n = start.size();
    if (n <= 0) return 0;
    
    Data arr[n];
    
    for (int i = 0; i < n; i++) {
            arr[i].start = start[i];
            arr[i].end = end[i];
        }
    
     sort(arr, arr + n, comp);
    
    int cnt = 1;
    int freeTime = arr[0].end;
    
    for(int i=1; i<n; i++){
        if(arr[i].start> freeTime){
            cnt++;
            freeTime = arr[i].end;
        }
    }
    return cnt;
    }
};