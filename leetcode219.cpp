class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        // vector<pair<int,int>> v;
        // for(int i=0; i<n; i++){
        //   v.push_back({nums[i],i});
        // }
        // sort(v.begin(),v.end());
        // for(int i=0; i<v.size()-1; i++){
        //     pair<int,int> p = v[i];
        //     pair<int,int> p2 = v[i+1];
        //     if(p.first == p2.first){
        //         if(abs(p.second - p2.second) <= k) return true;
        //     }
        // }
        // return false;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) mp[nums[i]] = i;

        for(int i = 0; i < n; i++){
            if(mp.count(nums[i])){
                if(i != mp[nums[i]] && abs((int)i-(int)mp[nums[i]]) <= k) return true;
                else mp[nums[i]] = i;
            }
        }
        return false;
    }
};