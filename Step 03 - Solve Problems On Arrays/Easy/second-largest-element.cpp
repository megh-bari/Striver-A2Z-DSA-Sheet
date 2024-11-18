#include <bits/stdc++.h>
using namespace std;

int secondLarge(int arr[], int n)
{
    int largest = arr[0];
    int sLargest = -1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            sLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > sLargest)
        {
            sLargest = arr[i];
        }
    }
    return sLargest;
}

int secondSmall(int arr[], int n)
{
    int smallest = arr[0];
    int secondSmallest = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] != smallest && arr[i] < secondSmallest)
        {
            secondSmallest = arr[i];
        }
    }
    return secondSmallest;
}

void find_secondLargest(int arr[], int n)
{
    int secondLargest = secondLarge(arr, n);
    int secondSmallest = secondSmall(arr, n);
    cout << "Second Largest: " << secondLargest << endl;
    cout << "Second Smallest: " << secondSmallest << endl;
}

int main()
{
    int n;
    cin >> n;

    if (n < 2) 
    {
        cout << "Array must have at least 2 elements!" << endl;
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    find_secondLargest(arr, n);

    return 0;
}
