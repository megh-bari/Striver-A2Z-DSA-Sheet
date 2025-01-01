#include <bits/stdc++.h>

using namespace std;

// find max element
int findMaxElement(vector<int> &piles)
{
    int n = piles.size();
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, piles[i]);
    }
    return maxi;
}

// find total hours

long long findTotalHours(vector<int> &piles, int hours)
{
    long long totalHours = 0;
    int n = piles.size();
    for (int i = 0; i < n; i++)
    {
        totalHours += ceil((double)piles[i] / (double)hours);
    }

    return totalHours;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int low = 1, high = findMaxElement(piles);
    int ans = INT_MAX;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        long long totalHours = findTotalHours(piles, mid);
        if (totalHours <= h)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}