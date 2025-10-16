class Solution {
public:

    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n);
        int pre = nums[0];
        prefix[0] = pre;
        for(int i = 1; i < n; i++){
            prefix[i] = pre + nums[i];
            pre = prefix[i];
        }

        unordered_map<int,int> mp; // prefix sum   index
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int tgt = prefix[i]-k;
            if(prefix[i] == k) cnt++;
            if(mp.find(tgt) != mp.end()){
                cnt += mp[tgt];
            }
            
            mp[prefix[i]]++;
            
        }
        return cnt;
    }
};