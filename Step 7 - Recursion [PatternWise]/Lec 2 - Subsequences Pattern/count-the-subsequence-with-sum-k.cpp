#include <bits/stdc++.h>

using namespace std;

int printS(int ind, int s, int sum, int arr[], int n)
{
    // condition not satisfied
    // stricly done if array contains positive only
    if (sum > 0)
        return 0;
    if (ind == n)
    {
        // condition statisfied
        if (s == sum)
        {
            // for (auto it : ds)
            //     cout << it << " ";
            // cout << endl;
            return 1;
        }
        // condition not satisfied
        else
            return 0;
    }

    s += arr[ind];

    int left = printS(ind + 1, s, sum, arr, n);

    s -= arr[ind];

    // not pick
    int right = printS(ind + 1, s, sum, arr, n);

    return left + right;
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    cout << printS(0, 0, sum, arr, n);

    return 0;
}