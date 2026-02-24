class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(), arrSum = 0, sum = 0, temp1 = nums[0];
        for(int i = 0; i < n; i++) arrSum += nums[i];

        for(int i = 0; i < n; i++){
            sum += nums[i];
            temp1 = max(temp1,sum);
            if(sum < 0) sum = 0;
        }
        
        int temp2 = -nums[0];
        sum = 0;
        for(int i = 0; i < n; i++){
            sum += (-nums[i]);
            temp2 = max(temp2,sum);
            if(sum < 0) sum = 0;
        }
        
        if(arrSum+temp2 == 0) return temp1;
        return max(arrSum+temp2,temp1);

    }
};