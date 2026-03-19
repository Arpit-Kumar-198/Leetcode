class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> temp;
        for(auto arr : intervals) temp.push_back(arr);
        temp.push_back(newInterval);
        sort(temp.begin(),temp.end());
        vector<vector<int>> ans;
        int i = 1;
        ans.push_back(temp[0]);
        while(i < temp.size()){
            if(temp[i][0] <= ans.back()[1])
                ans.back()[1] = max(ans.back()[1],temp[i][1]);
            else ans.push_back(temp[i]);
            i++;
        }
        return ans;
    }
};