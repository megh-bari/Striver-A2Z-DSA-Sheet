#include <bits/stdc++.h>

using namespace std;

// brute

int findNCR(int n, int r)
{
    int res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

// better + optimal

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;

    for (int i = 0; i < numRows; i++)
    {
        vector<int> ansRow(i + 1, 1);

        for (int j = 1; j < i; j++)
        {
            ansRow[j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
        ans.push_back(ansRow);
    }
    return ans;
}
