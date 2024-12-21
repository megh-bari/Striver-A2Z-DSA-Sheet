#include <bits/stdc++.h>

using namespace std;

// brute

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
{

    int n = a.size();
    int m = b.size();

    long long c[n + m];
    int left = 0;
    int right = 0;
    int index = 0;

    while (left < n && right < m)
    {
        if (a[left] <= b[right])
        {
            c[index] = a[left];
            left++, index++;
        }
        else
        {
            c[index] = b[right];
            right++, index++;
        }
    }

    while (left < n)
    {
        c[index++] = a[left++];
    }
    while (right < m)
    {
        c[index++] = b[right++];
    }

    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
            a[i] = c[i];
        else
            b[i - n] = c[i];
    }
}

// optimal 1: 2 pointer

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
{
    int n = a.size();
    int m = b.size();
    int left = n - 1;
    int right = 0;

    while (left >= 0 && right < m)
    {
        if (a[left] > b[right])
        {
            swap(a[left], b[right]);
            left--, right++;
        }
        else
        {
            break;
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

// optimal 2 : gap method

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
{
    int n = a.size();
    int m = b.size();
    int len = n + m;
    int gap = (len / 2) + (len % 2);

    while (gap > 0)
    {
        int left = 0;
        int right = gap;

        while (right < len)
        {
            if (left < n && right < n)
            {
                // both pointer in array 'a'
                if (a[left] > a[right])
                    swap(a[left], a[right]);
            }
            else if (left < n && right >= n)
            {
                // pointer in 'a' and 'b'
                if (a[left] > b[right - n])
                    swap(a[left], b[right - n]);
            }
            else
            {
                // both pointers in array 'b'
                if (b[left - n] > b[right - n])
                    swap(b[left - n], b[right - n]);
            }

            left++;
            right++;
        }

        if (gap == 1)
            gap = 0;
        else
            gap = (gap / 2) + (gap % 2);
    }
}