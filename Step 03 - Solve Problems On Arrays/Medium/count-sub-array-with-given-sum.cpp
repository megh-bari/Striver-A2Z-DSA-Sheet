#include<bits/stdc++.h>

using namespace std;


// better 
int findAllSubarraysWithGivenSum(vector<int> &arr, int k) {
  int cnt = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == k) {
                cnt++;
            }
        }
    }
    return cnt;
}
// TC - 0(N^2)


// optimal
 int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mpp;
        mpp[0]=1;
        int preSum=0, cnt=0;

        for(int i=0; i<n; i++){
            preSum+=nums[i];
            int remove = preSum-k;
            cnt+=mpp[remove];
            mpp[preSum]+=1;
        }
        return cnt;
    }

int main(){
    return 0;
}