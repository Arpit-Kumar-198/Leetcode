class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp,need;
        for(auto i : nums){
            mp[i]++;
        }
        for(auto i : nums){
            if(mp[i] == 0) continue;
            if(need[i] > 0){
                need[i]--;
                mp[i]--;
                need[i+1]++;
            }
            else{
                if(mp[i] > 0 && mp[i+1] > 0 && mp[i+2] > 0){
                    mp[i]--,mp[i+1]--,mp[i+2]--;
                    need[i+3]++;
                }
                else return false;
            }
        }
        return true;
    }
};