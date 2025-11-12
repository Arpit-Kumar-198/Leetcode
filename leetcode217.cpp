class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        // sort(nums.begin(),nums.end());
        // for(int i = 1; i < n; i++)
        // {
        //     if(nums[i]==nums[i-1]) return true;
        // }
        // return false;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) mp[nums[i]]++;
        for(auto it : mp){
            if(it.second >= 2) return true;
        }
        return false;
    }
};