class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n)
        {
            if(nums[i] <= 0) i++;
            else if(nums[i] > n || nums[i] == i+1 || nums[nums[i]-1] == nums[i]) i++;
            else swap(nums[nums[i]-1], nums[i]);
        }
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != i+1) return i+1;
        }
        return n+1;
    }
};
// HARD
