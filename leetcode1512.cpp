class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) mp[nums[i]]++;
        for(auto it : mp){
            long long x = it.second;
            cnt += ((x*(x-1))/2);
        }
        return (int)cnt;
    }
};