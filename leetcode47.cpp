class Solution {
public:
void helper(vector<int> arr, vector<int>& temp, vector<vector<int>>& ans){
        if(arr.size() == 0) {
            ans.push_back(temp);
            return;
        }
        unordered_set<int> st;
        for (int i = 0; i < arr.size(); i++){
            if(st.count(arr[i])) continue;
            temp.push_back(arr[i]);
            st.insert(arr[i]);
            vector<int> v;
            for(int j = 0; j < arr.size(); j++) 
                if(j != i) v.push_back(arr[j]);
            helper(v,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums,temp,ans);
        return ans;
    }
};