class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int p = 1, ans = INT_MIN;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) {
                ans = max(ans,nums[i]);
                p = 1;
            }
            else {
                p *= nums[i];
                ans = max(ans,p);
            }
        }
        p = 1;
        for(int i = n-1; i >= 0; i--){
            if(nums[i] == 0) {
                ans = max(ans,nums[i]);
                p = 1;
            }
            else {
                p *= nums[i];
                ans = max(ans,p);
            }
        }
        return ans;
    }
};