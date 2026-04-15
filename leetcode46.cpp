class Solution {
public:
    void helper(int idx, vector<int> arr, vector<vector<int>>& ans){
        if(idx == arr.size()) {
            ans.push_back(arr);
            return;
        }
        
        for (int i = idx; i < arr.size(); i++){
            swap(arr[i], arr[idx]);
            helper(idx+1, arr, ans);
            swap(arr[i], arr[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(0, nums, ans);
        return ans;
    }
};