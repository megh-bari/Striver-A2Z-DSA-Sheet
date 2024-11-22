#include <bits/stdc++.h>

using namespace std;

// better
int missingNum(int arr[], int n)
{
    int hash[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 0)
        {
            return i;
        }
    }
}

// optimal

int missNum(int arr[], int n)
{
    int sum = n * (n + 1) / 2;
    int s2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        s2 += arr[i];
    }
    return (sum - s2);
}

//  better optimal

int missingNumber(int arr[], int n)
{
    int xor1 = 0;
    int xor2 = 0;
    for (int i = 0; i <= n; i++)
    {
        xor1 = xor1 ^ i;
    }

    for (int i = 0; i < n - 1; i++)
    {
        xor2 = xor2 ^ arr[i];
    }
    return (xor1 ^ xor2);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // int missingNumber = missingNum(arr,n);
    // cout<<missingNumber;

    // cout<<missNum(arr,n);

    cout << missingNumber(arr, n);

    return 0;
}