class Solution {
public:

    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();

        vector<int> prefix(n);
        int pre = nums[0];
        prefix[0] = pre;
        for(int i = 1; i < n; i++){
            prefix[i] = pre + nums[i];
            pre = prefix[i];
        }
                   // val // freq
        unordered_map<int,int> m;
        for(int i = 0; i < n; i++){
            int d = prefix[i] - k;
            if(m.find(d) != m.end()) cnt += m.find(d)->second;
            if(prefix[i] == k) cnt++;
            m[prefix[i]] += 1;
        }
        return cnt;
    }
};