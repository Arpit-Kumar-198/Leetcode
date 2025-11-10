class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        vector<int> res;
        int cnt = 0;
        for(auto it : mp){
            if(cnt == 2) break;
            if(it.second == 1) {
                res.push_back(it.first);
                cnt++;
            }
        }
        return res;
    }
};