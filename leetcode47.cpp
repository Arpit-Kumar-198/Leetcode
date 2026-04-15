class Solution {
public:
void helper(int idx, vector<int> arr, vector<vector<int>>& ans){
        if(idx == arr.size()) {
            ans.push_back(arr);
            return;
        }
        unordered_set<int> seen;
        for (int i = idx; i < arr.size(); i++){
            if(seen.count(arr[i])) continue;

            seen.insert(arr[i]);
            swap(arr[i], arr[idx]);
            helper(idx+1, arr, ans);
            swap(arr[i], arr[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        helper(0, nums, ans);
        return ans;
    }
};