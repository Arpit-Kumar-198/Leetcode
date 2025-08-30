class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
         int n = nums.size(), m = queries.size();
         sort(nums.begin(),nums.end());
        vector<int> pre(n);
        vector<int> ans(m);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++)
        {
            pre[i] = pre[i-1]+nums[i];
        }
        
         for(int i = 0; i < m; i++)
        {
            int idxPre = -1;
            int cPre = 0;
            for(int j = 0; j < n; j++)
            {
                if(queries[i]>=pre[j]) {
                    idxPre = j;
                    cPre++;
                }
            }
           ans[i] = cPre;
        }
        return ans;
    }
};

// 2nd method 
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
         int n = nums.size(), m = queries.size();
         sort(nums.begin(),nums.end());
        vector<int> pre(n);
        vector<int> ans(m);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++)
        {
            pre[i] = pre[i-1]+nums[i];
        }
        
         for(int i = 0; i < m; i++)
        {
            int idxPre = -1;
    
            int lo = 0, hi = n-1;
            while(lo <= hi)
            {
                int mid = lo + (hi-lo)/2;
                if(pre[mid] <= queries[i])
                {
                    idxPre = mid;
                    lo++;
                }
                else hi--;
            }
            ans[i] = idxPre+1;
        }
        return ans;
    }
};