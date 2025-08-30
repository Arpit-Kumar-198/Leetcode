class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int minLen = INT_MAX;
        int sum = 0;
        int len = 0;
        
        int i = 0, j = 0;
        while(j < n)
        {
            sum += nums[j];
            while(sum >= target)
            {
                len = j-i+1;
                minLen = min(minLen,len);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        if(len == 0) return 0;
       else return minLen;
    }
};