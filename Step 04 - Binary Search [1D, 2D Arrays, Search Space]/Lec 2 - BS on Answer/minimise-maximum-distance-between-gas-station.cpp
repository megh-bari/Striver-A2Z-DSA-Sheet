// better on using PQ

#include <bits/stdc++.h>

using namespace std;

long double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howMany(n - 1, 0);
    priority_queue<pair<long double, int>> pq;

    // Push initial differences into the priority queue
    for (int i = 0; i < n - 1; i++)
    { // Corrected loop condition
        long double diff = arr[i + 1] - arr[i];
        pq.push({diff, i});
    }

    // Place gas stations
    for (int gasStations = 1; gasStations <= k; gasStations++)
    { // Corrected loop syntax
        auto tp = pq.top();
        pq.pop(); // Corrected the typo pq.top() -> pq.pop()
        int secIndex = tp.second;
        howMany[secIndex]++;
        long double iniDiff = arr[secIndex + 1] - arr[secIndex];
        long double newSecLen = iniDiff / (howMany[secIndex] + 1); // Corrected formula
        pq.push({newSecLen, secIndex});
    }

    return pq.top().first;
}


// Optimal: BS 

#include <bits/stdc++.h>

int numberOfGasstationReq(long double dist, vector<int> &arr) {
    int cnt = 0;
    for (int i = 1; i < arr.size(); i++) {
        int numberInBetween = (arr[i] - arr[i - 1]) / dist;
        cnt += numberInBetween; 
    }
    return cnt;
}


long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();
    long double low = 0;
    long double high = 0;

    
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    long double diff = 1e-6;
    while (high - low > diff) {
        long double mid = low + (high - low) / 2.0;
        int cnt = numberOfGasstationReq(mid, arr);
        if (cnt > k) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return high;
}
