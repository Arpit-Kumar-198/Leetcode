class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it : nums) mp[it]++;
        int cnt = 0;
        for(auto it : mp){
            cnt += (it.second*(it.second-1))/2;
        }
        return cnt;
    }
};