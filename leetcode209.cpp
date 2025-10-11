class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

    //     int minLen = INT_MAX;
    //     int sum = 0;
    //     int len = 0;
        
    //     int i = 0, j = 0;
    //     while(j < n)
    //     {
    //         sum += nums[j];
    //         while(sum >= target)
    //         {
    //             len = j-i+1;
    //             minLen = min(minLen,len);
    //             sum -= nums[i];
    //             i++;
    //         }
    //         j++;
    //     }
    //     if(len == 0) return 0;
    //    else return minLen;


        int mnlen = INT_MAX;
        int i = 0, j = 0;
        int sum = 0;

        
   
        while(j < n)
        {
            if(sum >= target){
                mnlen = min(mnlen,j-i);
                sum -= nums[i];
                i++;
            }
            else {
                sum += nums[j];
                j++;
            }
        }
        while(i < n)
        {
            if(sum >= target){
                mnlen = min(mnlen,j-i);
                sum -= nums[i];
                i++;
            }
            else {
                break;
            }
        }
        return mnlen == INT_MAX ? 0 : mnlen;
    }
};