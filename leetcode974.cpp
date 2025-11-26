class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1; 
        long long prefix = 0;
        int count = 0;

        for (int x : nums) {
            prefix += x;
            int mod = ((prefix % k) + k) % k; 

            count += mp[mod];

            mp[mod]++;
        }

        return count;
    }
};