class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    int n = nums.size(), i = 0, j = 0, n0 = 0, ans = 0;
    while(j < n){
        if(nums[j] == 0) n0++;
        while(i < n && n0 > k){
            if(nums[i] == 0) n0--;
            i++;
        }
        ans = max(ans,j-i+1);
        j++;
    }
    return ans;
    }
};