class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // if(nums.size() == 0) return 0;
        // sort(nums.begin(), nums.end());
        // int mxlen = INT_MIN;
        // int len = 1;
        // for(int i = 1; i < nums.size(); i++){
        //     if(nums[i] == nums[i-1]) continue;
        //     else if(nums[i] == nums[i-1]+1) len++;
        //     else{
        //         mxlen = max(mxlen,len);
        //         len = 1;
        //     }
        // }
        // mxlen = max(mxlen,len);
        // len = 1;
        // return mxlen;
        unordered_set<int> st;
        for(auto num : nums) st.insert(num);
        int mxlen = 0;
        for(auto it : st){
            if(st.count(it-1) == 0){
                int len = 1;
                int next = it+1;
                while(st.find(next) != st.end()) len++, next++;
                mxlen = max(len,mxlen);
            }
        }
        return mxlen;
    }
};