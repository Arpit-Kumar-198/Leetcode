// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> prefix(n);
//         vector<int> suffix(n);
//         int p = nums[0];
//         prefix[0] = 1;
//         for(int i = 1; i < n; i++){
//             prefix[i] = p;
//             p *= nums[i];
        
//         }
//         p = nums[n-1];
//         suffix[n-1] = 1;
//         for(int i = n-2; i >= 0; i--) {
//             suffix[i] = p;
//             p *= nums[i];

//         }
//         for(int i = 0; i < n; i++) nums[i] = suffix[i]*prefix[i];
//         return nums;
//     }
// };

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> res(n);
        res[0] = nums[0];
        for(int i = 1; i < n; i++) res[i] = res[i-1]*nums[i];

        for(int i = n-2; i >= 0; i--) nums[i] = nums[i]*nums[i+1];

        int track;
        for(int i = 0; i < n; i++){
            if(i == 0) {
                track = res[i];
                res[i] = nums[i+1];
            }
            else if(i == n-1){
                res[i] = track;
            }
            else{
                int t = res[i];
                res[i] = track*nums[i+1];
                track = t;
            }
        }
        return res;
    }
};