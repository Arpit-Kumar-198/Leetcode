class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int prev = INT_MIN;
        for(int i = 0; i < n; i++){
            if(nums[i] == prev) continue;
            else prev = nums[i];

            int tgt = - nums[i], lo = i+1, hi = n-1;
            while(lo < hi){
                if(nums[lo]+nums[hi] == tgt){
                    // work
                    vector<int> temp = {nums[i], nums[lo], nums[hi]};
                    res.push_back(temp);
                    while(lo < n-1 && nums[lo] == nums[lo+1]) lo++;
                    lo++;
                    while(hi > 0 && nums[hi] == nums[hi-1]) hi--;
                }
                else if(nums[lo]+nums[hi] < tgt) lo++;
                else hi--;
            }
        }
        return res;
    }
};