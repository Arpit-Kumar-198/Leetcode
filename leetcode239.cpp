class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            int n = nums.size();
            vector<int> nge(n);
            vector<int> ans;
            nge[n-1] = n;
            stack<int> st;
            st.push(n-1);
            for(int i = n-2; i >= 0; i--){
                while(st.size()!=0 && nums[st.top()]<=nums[i]) st.pop();
                if(st.size()==0) nge[i] = n;
                else nge[i] = st.top();
                st.push(i);
            }
            int i = 0, j = k-1;
            while(j < n){
                int l = nums[i];
                int r = i+k;
                int k = i;
                while(nge[k]<r){
                    k = nge[k];
                }
                ans.push_back(nums[k]);
                i++,j++;
            }
            return ans;
        }
    };