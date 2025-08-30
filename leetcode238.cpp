// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         int product = 1, p2=1;
//         int noz = 0;
//         for(int i = 0; i < n; i++) {
//             if(nums[i]==0) noz++;
//             product *= nums[i];
//            if(nums[i]!=0) p2 *= nums[i];
//         }
//         if(noz>1) p2 = 0;
//         for(int i = 0; i < n; i++)
//         {
//             if(nums[i]==0) nums[i]=p2;
//         else nums[i] = product/nums[i];
//         }
//         return nums;
//     }
// };

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        int p = nums[0];
        prefix[0] = 1;
        for(int i = 1; i < n; i++){
            prefix[i] = p;
            p *= nums[i];
        
        }
        p = nums[n-1];
        suffix[n-1] = 1;
        for(int i = n-2; i >= 0; i--) {
            suffix[i] = p;
            p *= nums[i];

        }
        for(int i = 0; i < n; i++) nums[i] = suffix[i]*prefix[i];
        return nums;
    }
};