class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        vector<int> dp1(n-1, -1);
        vector<int> dp2(n-1, -1);

        dp1[n-2] = nums[n-2];
        dp1[n-3] = max(nums[n-3], dp1[n-2]);

        for(int i = n-4; i >= 0; i--)
            dp1[i] = max(nums[i]+dp1[i+2], dp1[i+1]);

        dp2[n-2] = nums[n-1];
        dp2[n-3] = max(nums[n-2], dp2[n-2]);

        for(int i = n-4; i >= 0; i--)
            dp2[i] = max(nums[i+1]+dp2[i+2], dp2[i+1]);

        return max(dp1[0], dp2[0]);
    }
};