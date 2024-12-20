#include <bits/stdc++.h>

using namespace std;

// better

int subarraysWithSumK(vector<int> a, int b)
{
    int n = a.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int currentXor = 0;
        for (int j = i; j < n; j++)
        {
            currentXor = currentXor ^ a[j];
            if (currentXor == b)
                cnt++;
        }
    }
    return cnt;
}

//  optimal

int subarraysXor(vector<int> &arr, int x)
{
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++;
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        xr = xr ^ arr[i];
        int y = xr ^ x;
        cnt += mpp[y];
        mpp[xr]++;
    }

    return cnt;
}