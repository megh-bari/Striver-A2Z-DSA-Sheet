class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> res;
        int i = 0, n = intervals.size();

        // Step 1: Add all intervals that come before the new interval (left part)
        // These intervals end before the new interval starts, so no overlap
        while (i < n && intervals[i][1] < newInterval[0])
        {
            res.push_back(intervals[i]);
            i++;
        }

        // Step 2: Merge all overlapping intervals with the new interval (middle part)
        // Overlap occurs when the start of the current interval is <= the end of newInterval
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            // Update the newInterval to cover the merged interval range
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        res.push_back(newInterval);

        // Step 3: Add all intervals that come after the new interval (right side)
        // These intervals start after the new interval ends, so no overlap
        while (i < n)
        {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};
