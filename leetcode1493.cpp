class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, i = 0, j = 0, n0 = 0;
        // while(i < n && j < n){
        //     if(nums[j] == 1) {
        //         if(n0 != 0) ans = max(ans,j-i);
        //         else ans = max(ans,j-i+1);
        //     }
        //     else{
        //         if(n0 == 0){
        //             n0++;
        //             if(n0 != 0) ans = max(ans,j-i);
        //             else ans = max(ans,j-i+1);
        //         }
        //         else{
        //             while(i < n && nums[i] != 0) i++;
        //             i++;
        //         }
        //     }
        //     j++;
        // }
        // if(j == n && n0 == 0) return ans-1;
        // return ans;
        
        while(j < n){
            if(nums[j] == 0) n0++;
            while(n0 > 1){
                if(nums[i] == 0) n0--;
                i++;
            }
            ans = max(ans,j-i); // delete exactly 1 element 
            j++;
        }
        return ans;
    }
};