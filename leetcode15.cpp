class Solution {
public:
bool present(vector<vector<int>>& res, vector<int>& v){
    for(int i = 0; i < res.size(); i++){
        if(res[i] == v) return true;
    }
    return false;
}
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int i = 0;
        int j = i+1, k = n-1;
        while(i <= n-3){
            j = i+1, k = n-1;
            int tgt = nums[i]*(-1);
            while(j < k){
                if(nums[j] + nums[k] == tgt){
                    vector<int> v(3,0);
                    v[0] = nums[i];
                    v[1] = nums[j];
                    v[2] = nums[k];
                    j++,k--;
                    while(j <= n-2 && nums[j] == nums[j-1]) j++;
                    res.push_back(v);
                }
                else if(nums[j] + nums[k] < tgt) j++;
                else k--;
            }
            i++;
            while(i <= n-3 && nums[i] == nums[i-1]) i++;
        }
        return res;
    }
};