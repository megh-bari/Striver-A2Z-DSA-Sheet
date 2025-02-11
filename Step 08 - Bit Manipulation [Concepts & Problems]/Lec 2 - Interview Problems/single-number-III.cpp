// using hashing

vector<int> singleNumber(vector<int>& nums) {
    vector<int> ans;
    map<int, int> mpp;

    for (int i = 0; i < nums.size(); i++) {
        mpp[nums[i]]++;
    }

    for (auto it : mpp) {
        if (it.second == 1)
            ans.push_back(it.first);
    }

    return ans;
}

// optimal using bucket concept 

vector<int> singleNumber(vector<int>& nums) {
    long xorr = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        xorr = xorr ^ nums[i];
    }
    int rightMost = (xorr & xorr - 1) ^ xorr;
    int b1 = 0, b2 = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] & rightMost) {
            b1 = b1 ^ nums[i];
        } else {
            b2 = b2 ^ nums[i];
        }
    }
    return {b1, b2};
}