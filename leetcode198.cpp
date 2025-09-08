class Solution {
public:
int helper(vector<int>& nums, int s, vector<int>& dp){
    if(s > nums.size()-1) return 0;
    if(s == nums.size()-1) return dp[s] = nums[s];
    if(dp[s] != -1) return dp[s];
    return dp[s] = max(nums[s]+helper(nums,s+2,dp), helper(nums,s+1,dp));
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return helper(nums,0,dp);
    }
};