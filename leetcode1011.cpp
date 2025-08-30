class Solution {
public:
bool check(int mid, vector<int>& weights, int days)
{
    int n = weights.size(), count = 0;
    int m = mid;
    for(int i = 0; i < n; i++)
    {
        if(m >= weights[i]) m -= weights[i];
        else
        {
            count++;
            m = mid;
            m -= weights[i];
        }
    }
    count += 1;
    if(count > days) return false;
    else return true;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int max = INT_MIN, sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(weights[i] > max) max = weights[i];
            sum += weights[i];
        }
        int lo = max;
        int hi = sum;
        int minCap = sum;
        while(lo <= hi)
        {
            int mid = lo + (hi-lo)/2;
            if(check(mid, weights, days))
        {
            minCap = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
        }
        // T.C. = n*log(sum-max)
        return minCap;
    }
};