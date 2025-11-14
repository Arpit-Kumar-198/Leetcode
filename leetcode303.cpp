class NumArray {
public:
    vector<int> nums;
    vector<int> prefixArr;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            prefix[i] = prefix[i-1]+nums[i];
        }
        prefixArr = prefix;
    }
    
    int sumRange(int left, int right) {
        // int s = 0;
        // for(int i = left; i <= right; i++){
        //     s += nums[i];
        // }
        int s;
        if(left!=0) s = prefixArr[right] - prefixArr[left-1];
        else s = prefixArr[right];
        return s;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */