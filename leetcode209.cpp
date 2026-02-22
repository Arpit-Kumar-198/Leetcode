class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int mnlen = INT_MAX, i = 0, j = 0, sum = 0;
        while(j < n){
            sum += nums[j];
            if(sum >= target) mnlen = min(mnlen,j-i+1);
            while(i < n && sum >= target){
                mnlen = min(mnlen,j-i+1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        if(mnlen == INT_MAX) return 0;
        return mnlen;
    }
};