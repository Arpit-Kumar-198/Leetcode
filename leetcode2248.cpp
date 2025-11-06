class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<unordered_set<int>> v(n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < nums[i].size(); j++){
                v[i].insert(nums[i][j]);
            }
        }
        vector<int> res;

        for(auto it : v[0]){
        bool flag = true;
        for (int j = 1; j < n; j++)
        {
            if(v[j].count(it) == 0){
                flag = false;
                break;
            }
        }
        if(flag) res.push_back(it);
    }
    sort(res.begin(),res.end());
    return res;
    }
};