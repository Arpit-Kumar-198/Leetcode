class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        
        int cnt = 0;
        unordered_map<int,unordered_set<int>> mp;
        for(int i = 0; i < n; i++) mp[nums[i]].insert(i);
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j+1; k < n; k++){
                    if(mp.count(nums[i]+nums[j]+nums[k])) for(auto it : mp[nums[i]+nums[j]+nums[k]]) if(it > k) cnt++;
                }
            }
        }
        return cnt;
    }
};