class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 1; i < n; i++) nums[i] = nums[i]+nums[i-1];
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) mp[(nums[i]%k + k)%k]++;
        int ans = 0;
        for(auto it : mp) {
            if(it.first == 0) ans += it.second;
            ans += (it.second*(it.second-1))/2;
        }
        return ans;
    }
};