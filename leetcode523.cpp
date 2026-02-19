class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 1; i < n; i++) nums[i] = nums[i]+nums[i-1];
        unordered_map<int,pair<int,int>> mp;
        for(int i = 0; i < n; i++) nums[i] = nums[i]%k;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0 && i > 0) return true;
            if(mp.find(nums[i]) != mp.end()){
                mp[nums[i]].first++;
                if(mp[nums[i]].first > 2) return true;
                if(mp[nums[i]].first == 2 && i-mp[nums[i]].second > 1) 
                    return true;
            }
            else{
                mp[nums[i]].first++;
                mp[nums[i]].second = i;
            }
        }
        return false;
    }
}; 