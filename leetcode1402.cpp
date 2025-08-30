class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<int> suff(n);
        sort(satisfaction.begin(),satisfaction.end());  //sort array
        //suffix sum 
        suff[n-1] = satisfaction[n-1];
        for(int i = n-2; i >= 0; i--)
        {
            suff[i] = satisfaction[i]+suff[i+1];
        }

        //find pivot index
        int idx = -1;
        for(int i = 0; i < n; i++)
        {
            if(suff[i]>=0)
            {
                idx = i;
                break;
            }
        }
        // return 0 if idx = -1
        if(idx == -1) return 0;

        //find like-time coefficient
        int ans = 0;
        int a = 1;
         for(int i = idx; i < n; i++)
        {
            ans += (a*satisfaction[i]);
            a++;
        }
       
        return ans;

    }
};