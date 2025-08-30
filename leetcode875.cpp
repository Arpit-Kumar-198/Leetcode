class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int max = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            if(piles[i] > max) max = piles[i];
        }
        int lo = 1;
        int hi = max;
        int ans = 1;
        while(lo <= hi)
        {
            int mid = lo + (hi-lo)/2;
            long long count = 0;
            for(int i = 0; i < n; i++)
            {
                if(piles[i]%mid != 0) count += (piles[i]/mid + 1);
                else count += (piles[i]/mid);
            }
            if(count > h) lo = mid + 1;
            else{
                ans = mid;
                hi = mid - 1;
            }
        }
        return ans;
    }
};