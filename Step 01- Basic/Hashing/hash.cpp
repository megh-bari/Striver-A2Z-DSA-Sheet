#include <bits/stdc++.h>

using namespace std;

// int count_occurrences(int n, int arr[], int target)
// {
//     int cnt = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == target)
//         {
//             cnt += 1;
//         }
//     }
//     return cnt;
// }

int main()
{
        // ****
    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    //     cin >> arr[i];
    // prob 1
    // precompute
    // int hash[13] = {0};
    // for (int i = 0; i < n; i++)
    // {
    //     hash[arr[i]] += 1;
    // }
    // int target;
    // cin >> target;
    // while (target--)
    // {
    //     int number;
    //     cin >> number;

    //     // fetch
    //     cout << hash[number] << endl;
    // }

    // cout << count_occurrences(n, arr, target);

    // ****

    // prob 2
    // string s;
    // cin>>s;
    // // precompute
    // int hash[26]={0};
    // for(int i=0; i<s.size(); i++) hash[s[i]-'A']++;

    // int q;
    // cin>>q;
    // while(q--){
    //     char c;
    //     cin>>c;
    //     // fetch
    //     cout<<hash[c-'A']<<endl;
    // }


    //* map
    

    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    // precompute

     unordered_map<int,int> mpp;
    for(int i=0; i<n;i++){
        mpp[arr[i]]++;
    }

    // for how it store in sorted order
    for(auto it: mpp){
        cout<<it.first<<" ->"<<it.second<<endl;
    }

    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        // fetch
        cout<<mpp[num]<<endl;
    }

    

    return 0;
}
