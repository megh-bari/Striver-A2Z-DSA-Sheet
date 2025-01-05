#include <bits/stdc++.h>

using namespace std;

// book allocation logic
int countStudent(vector<int> &arr, int pages)
{
    int student = 1;
    long long pagesStudent = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (pagesStudent + arr[i] <= pages)
        {
            pagesStudent += arr[i];
        }
        else
        {
            student++;
            pagesStudent = arr[i];
        }
    }
    return student;
}

int findPages(vector<int> &arr, int n, int m)
{
    if (m > n)
        return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int no_Of_Stud = countStudent(arr, mid);

        if (no_Of_Stud > m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low;
}


int splitArray(vector<int> &nums, int k)
{
    return findPages(nums, nums.size(), k);
}
