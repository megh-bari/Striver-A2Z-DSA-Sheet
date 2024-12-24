#include <bits/stdc++.h>

using namespace std;

// brute

int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int product = 1;
            for (int k = j; k < n; k++)
            {
                product = product * nums[k];
                maxi = max(maxi, product);
            }
        }
    }
    return maxi;
}

// better

int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int product = 1;
        for (int j = i; j < n; j++)
        {
            product = product * nums[j];
            maxi = max(maxi, product);
        }
    }
    return maxi;
}

// optimal

int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    int maxi = INT_MIN;
    int prefix = 1, suffix = 1;
    for (int i = 0; i < n; i++)
    {
        if (prefix == 0)
            prefix = 1;
        if (suffix == 0)
            suffix = 1;
        prefix = prefix * nums[i];
        suffix = suffix * nums[n - i - 1];

        maxi = max(maxi, max(prefix, suffix));
    }
    return maxi;
}