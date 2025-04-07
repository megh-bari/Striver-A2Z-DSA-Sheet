class Solution
{
public:
    int solve(vector<int> &bt)
    {
        sort(bt.begin(), bt.end());

        int n = bt.size();
        int totalWaitingTime = 0;
        int currentTime = 0;

        for (int i = 0; i < n; i++)
        {
            totalWaitingTime += currentTime;
            currentTime += bt[i];
        }

        return totalWaitingTime / n;
    }
};