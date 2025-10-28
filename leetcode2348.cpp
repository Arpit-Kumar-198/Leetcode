class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,long long> mp;

        int k = 0;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            if(nums[i]==0){
                cnt++;
                while(i < n-1 && nums[i+1]==0){
                    cnt++;
                    i++;
                }
                mp[k]=cnt;
                k++;
            }
        }

        long long res = 0;
        for(auto it : mp){
            long long x = it.second;
            res += (x*(x+1)/2);
        }
        return res;

    }
};