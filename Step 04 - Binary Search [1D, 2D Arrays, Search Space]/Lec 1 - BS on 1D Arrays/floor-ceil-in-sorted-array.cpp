#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    int floor = -1, ceil = -1;

    // floor
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] <= x)
        {
            floor = a[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    //  ceil
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] >= x)
        {
            ceil = a[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return {floor, ceil};
}

// using c++ stl

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    auto ceil_it = lower_bound(a.begin(), a.end(), x);

    auto floor_it = upper_bound(a.begin(), a.end(), x);

    int floor = (floor_it != a.begin()) ? *(--floor_it)
                                        : -1;
    int ceil =
        (ceil_it != a.end()) ? *ceil_it : -1;

    return {floor, ceil};
}
