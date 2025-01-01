#include<bits/stdc++.h>

using namespace std;

    bool isPossible(vector<int>& bloomDay, int day, int m, int k) {
        int cnt = 0, no_of_bloomDay = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                cnt++;
            } else {
                no_of_bloomDay += (cnt / k);
                cnt = 0;
            }
        }
        no_of_bloomDay += (cnt / k);
        return no_of_bloomDay >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1LL * k * 1LL;
        int n = bloomDay.size();

        if (val > n)
            return -1;

        int mini = INT_MAX, maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        int low = mini, high = maxi;
        int ans = low;

        while(low<=high){
            int mid = low + (high - low)/2;

            if(isPossible(bloomDay, mid, m, k)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }