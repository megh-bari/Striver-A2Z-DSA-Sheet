#include <bits/stdc++.h>
using namespace std;

void leftRotateByOne(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}

// below code for certain number of rotation

void rotateByDPosition(vector<int> &arr, int n, int d)
{
    d = d % n;
    vector<int> temp(d);

    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[i];
    }

    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }

    for (int i = n - d; i < n; i++)
    {
        arr[i] = temp[i - (n - d)];
    }
}

// Or better way(reverse it)

void usingReverse(int arr[], int n, int d)
{
    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
    reverse(arr, arr + n);
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int d;
    cin >> d;

    // rotateByDPosition(arr, n, d);
    // usingReverse(arr, n,d);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
