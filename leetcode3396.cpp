class Solution {
public:
    bool check(unordered_map<int,int>& mp){
        for(auto it : mp){
            if(it.second > 1) return false;
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto num : nums) mp[num]++;
        if(n == 1 || check(mp)) return 0;
        if(n == 2) {
            if(nums[0] == nums[1]) return 1;
            else return 0;
        }

        int ans = 0, i = 0;
        while(i < n){
            if(i < n) mp[nums[i]] -= 1;
            if(i+1 < n) mp[nums[i+1]] -= 1;
            if(i+2 < n) mp[nums[i+2]] -= 1;

            ans += 1;

            if(check(mp)) return ans;

            i += 3;
        }
        return ans;
    }
};