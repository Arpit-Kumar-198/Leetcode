class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int,int> mp;
        vector<long long> prefix(nums.size());

        for(int i = 0; i < nums.size(); i++) prefix[i] = (long long)nums[i];
        for(int i = 1; i < prefix.size(); i++) prefix[i]=prefix[i]+prefix[i-1];

        for(int i = 0; i < k; i++) mp[nums[i]]++;

        if(mp.size() == k) ans = max(ans, (long long)prefix[k-1]);
        int i = 1, j = k;
        
        while(j < nums.size()){
            mp[nums[i-1]]--;
            if(mp[nums[i-1]] == 0) mp.erase(nums[i-1]);
            mp[nums[j]]++;
            if(mp.size() == k) ans = max(ans, (long long)prefix[j] - (long long)prefix[i-1]);
            i++,j++;
        }
        return ans;
    }
};