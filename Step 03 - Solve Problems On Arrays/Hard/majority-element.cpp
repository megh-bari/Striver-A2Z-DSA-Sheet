#include <bits/stdc++.h>

using namespace std;

// better

vector<int> majorityElement(vector<int> v)
{
    vector<int> ls;
    map<int, int> mpp;

    int n = v.size();
    int mini = (int)(n / 3) + 1;

    for (int i = 0; i < n; i++)
    {
        mpp[v[i]]++;

        if (mpp[v[i]] == mini)
        {
            ls.push_back(v[i]);
        }
        if (ls.size() == 2)
            break;
    }
    sort(ls.begin(), ls.end());
    return ls;
}

// optimal
vector<int> majorityElement(vector<int> nums)
{
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == el1)
        {
            cnt1++;
        }
        else if (nums[i] == el2)
        {
            cnt2++;
        }
        else if (cnt1 == 0)
        {
            el1 = nums[i];
            cnt1 = 1;
        }
        else if (cnt2 == 0)
        {
            el2 = nums[i];
            cnt2 = 1;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = cnt2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == el1)
            cnt1++;
        else if (nums[i] == el2)
            cnt2++;
    }

    vector<int> ls;
    int mini = nums.size() / 3;
    if (cnt1 > mini)
        ls.push_back(el1);
    if (cnt2 > mini)
        ls.push_back(el2);

    sort(ls.begin(), ls.end());
    return ls;
}
