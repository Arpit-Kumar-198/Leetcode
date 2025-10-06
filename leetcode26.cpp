class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = 1;
        int idx = 1;
        
        // i → the fast pointer, scans every element of the array

        // idx → the slow pointer, keeps track of the position where the next unique element should go

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1]) {
                ans++;
                nums[idx] = nums[i];
                idx++;
            }
        }
        return ans;
    }
};