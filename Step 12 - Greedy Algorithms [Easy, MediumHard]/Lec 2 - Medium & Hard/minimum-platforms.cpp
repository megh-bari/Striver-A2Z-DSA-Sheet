// brute not optimal:
int findPlatform(vector<int>& arr, vector<int>& dep) {
    int n = arr.size();
    int maxCount = 0;
    for(int i=0; i<=n-1;i++){
        int count = 1;
        
        for(int j=i+1; j<n-1; j++){
          if ((arr[i] >= arr[j] && arr[i] <= dep[j]) || 
(arr[j] >= arr[i] && arr[j] <= dep[i])){
                count++;
            }
            maxCount = max(maxCount, count);
        }
    }
    return maxCount;
}

// optimal (sorting)

int findPlatform(vector<int>& arr, vector<int>& dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int n = arr.size();
    int i=0, j=0;
    int count =0, maxCount=0;
    
    while(i<n){
        if(arr[i]<=dep[j]){
            count++;
            i++;
        }else{
            count--;
            j++;
        }
        maxCount = max(maxCount, count);
    }
    return maxCount;
 }