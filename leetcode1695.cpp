class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, sum = 0, ans = 0;
        unordered_map<int,int> mp;
        while(j < n){
            if(mp.count(nums[j]) == 0){
                mp[nums[j]]++;
                sum += nums[j];
                ans = max(ans,sum);
                j++;
            }
            else{
                while(i < n && mp.count(nums[j]) != 0){
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0) mp.erase(nums[i]);
                    sum -= nums[i];
                    i++;
                }
            }
        }
        return ans;
    }
};