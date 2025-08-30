class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int c0 = 0;
        int maxLen = INT_MIN;
        int len = 0;

        int i = 0, j = 0;

        while(j < n)
        {
            if(j==0 && nums[j]==0) {
                c0 = 1;
                j++;
            }
            else if(nums[j]==1) j++;
            else
            {
                if(c0 == 0)
                {
                    c0 = 1;
                    j++;
                }
                else
                {
                    len = j-i-1;
                    maxLen = max(maxLen,len);
                    while(nums[i]==1) i++;
                    i++,j++;
                }
            }
        }
        len = j-i-1;
        maxLen =max(maxLen,len);
        if(c0 == 0) return nums.size()-1;
        else return maxLen;
    }
};