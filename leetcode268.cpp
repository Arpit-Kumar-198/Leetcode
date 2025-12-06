class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // int sum1 = 0, sum2 = 0;
        // for(int i = 0; i < n; i++) sum1 += nums[i];
        // sum2 = n*(n+1)/2;
        // return (sum2-sum1);

        int i = 0, currIdx = 0;
        while(i < n){
            currIdx = nums[i];
            if(nums[i] == i || nums[i] == n) i++;
            else{
                swap(nums[i],nums[currIdx]);
            }
        }
        for(int i = 0; i < n; i++){
            if(nums[i] != i) return i;
        }
        return n;
    }
};