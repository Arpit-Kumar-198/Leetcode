class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 1; i < n; i++) nums[i]=nums[i]+nums[i-1];
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == k) ans++;
            if(mp.find(nums[i]-k) != mp.end()) ans += mp[nums[i]-k];
            mp[nums[i]]++;
        }
        return ans;
    }
};