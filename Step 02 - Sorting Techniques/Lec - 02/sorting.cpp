#include <bits/stdc++.h>
using namespace std;

//  Merge Sort

void merge(vector<int> &arr, int low, int mid, int high)
{

    vector<int> temp;
    int left = low;      // low to mid
    int right = mid + 1; // mid+1....high

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void merge_sort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;

    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

void mergeSort(vector<int> &arr, int n)
{
    merge_sort(arr, 0, n - 1);
}

// Quick Sort

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i < high)
        {
            i++;
        }
        while (arr[j] > pivot && j > low)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quick_sort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);
        quick_sort(arr, low, partitionIndex - 1);
        quick_sort(arr, partitionIndex + 1, high);
    }
}

vector<int> quickSort(vector<int> arr)
{
    quick_sort(arr, 0, arr.size() - 1);
    return arr;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // mergeSort(arr, n);
    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
