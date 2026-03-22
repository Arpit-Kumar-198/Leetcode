class Solution {
public:
    void helper(vector<int> arr, vector<int>& temp, vector<vector<int>>& ans){
        if(arr.size() == 0) {
            ans.push_back(temp);
            return;
        }
        
        for (int i = 0; i < arr.size(); i++){
            temp.push_back(arr[i]);
            vector<int> v;
            for(int j = 0; j < i; j++) 
                v.push_back(arr[j]);
            for(int j = i+1; j < arr.size(); j++) 
                v.push_back(arr[j]);
            helper(v,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums,temp,ans);
        return ans;
    }
};