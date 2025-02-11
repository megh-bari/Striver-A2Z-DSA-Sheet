// not that much optimal, cuz here we distoring the array 

int singleNumber(vector<int>& nums) {
    int n = nums.size();
     sort(nums.begin(), nums.end());

    for(int i=1; i<n-1; i=i+3){
        if(nums[i]!=nums[i-1]){
            return nums[i-1];
        }
    }
    return nums[n-1];
}


//  most optimal using xor

int singleNumber(vector<int>& nums) {
    int ones = 0, twos =0;
    for(int i=0; i<nums.size(); i++){
     ones = ((ones^nums[i]) & ~twos);
     twos = ((twos^nums[i]) & ~ones);
    }
     return ones;
 }
