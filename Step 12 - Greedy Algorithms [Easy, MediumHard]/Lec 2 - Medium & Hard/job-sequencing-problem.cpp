class Solution {
    public:
    struct Jobs{
        int id;
        int profit;
        int deadline;
    };
    
    bool static comp (Jobs a, Jobs b){
        return (a.profit> b.profit);
    }
      vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
            int n = deadline.size();
          vector<Jobs> jobs(n);
          
          for(int i=0; i<n; i++){
              jobs[i].id = i+1;
              jobs[i].profit = profit[i];
              jobs[i].deadline = deadline[i];
          }
          
          sort(jobs.begin(), jobs.end(), comp);
          
          int maxDeadline = 0;
          for (int i = 0; i < n; i++) {
              maxDeadline = max(maxDeadline, jobs[i].deadline); 
          }
          
          vector<int>hash(maxDeadline+1, -1);
          int jobCount =0, jobProfit = 0;
          
          for(int i=0; i<n; i++){
        for (int j = jobs[i].deadline; j > 0; j--) { 
                  if(hash[j]==-1){
                      jobCount++;
                      hash[j]=jobs[i].id;
                      jobProfit+=jobs[i].profit;
                      break;
                  }
              }
          }
          return {jobCount, jobProfit};
      }
  };

// this hits you with TLE, so that you have to used DSU (graph) will do it on graph playlist
