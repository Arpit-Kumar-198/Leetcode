class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) prefix[i] = nums[i]+prefix[i-1];
        for(int i = 0; i < nums.size(); i++) prefix[i] -= nums[i];
        
        suffix[nums.size()-1] = nums[nums.size()-1];
        for(int i = nums.size()-2; i >= 0; i--) suffix[i] = nums[i] + suffix[i+1];
        for(int i = nums.size()-1; i >= 0; i--) suffix[i] -= nums[i];

        for(int i = 0; i < nums.size(); i++) prefix[i] = abs(prefix[i]-suffix[i]);
            
        return prefix;
    }
};