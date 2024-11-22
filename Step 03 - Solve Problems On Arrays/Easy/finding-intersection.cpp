#include <bits/stdc++.h>

using namespace std;

//  brute soln
vector<int> intersectionArray(int arr1[], int arr2[], int n1, int n2)
{
    vector<int> ans;
    int vis[n2] = {0};
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (arr1[i] == arr2[j] && vis[j] == 0)
            {
                ans.push_back(arr1[i]);
                vis[j] = 1;
                break;
            }
            if (arr2[j] > arr1[i])
                break;
        }
    }
    return ans;
}

// optimal

vector<int>intersection(int arr1[], int arr2[], int n1, int n2){
    int i=0;
    int j=0;
    vector<int>ans;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            i++;
        }else if(arr2[j]>arr1[i]){
            j++;
        }else{
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    int arr1[n1], arr2[n2];
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    // ***brute**
    // vector<int> intersection = intersectionArray(arr1, arr2, n1, n2);

    // for (int elem : intersection)
    // {
    //     cout << elem << " ";
    // }

    // ***Optimal***
    
    vector<int> inter = intersection(arr1, arr2, n1, n2);

    for (int elem : inter)
    {
        cout << elem << " ";
    }

    return 0;
}