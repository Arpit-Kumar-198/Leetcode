class Solution {
public:
bool check(long long mid, vector<int>& time, int totalTrips)
{
    int n = time.size();
    long long count = 0;
    for(int i = 0; i < n; i++)
    {
        count += mid/time[i];
    }
    if(count >= totalTrips) return true;
    else return false;
}
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        int min = INT_MAX;
        int max = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            if(time[i] < min) min = time[i];
            if(time[i] > max) max = time[i];
        }
        long long ans = min;
        long long lo = 1;
        long long hi = (long long)totalTrips*(long long)max;
        while(lo <= hi)
        {
            long long mid = lo + (hi-lo)/2;
            if(check(mid, time, totalTrips))
            {
                ans = mid;
                hi = mid - 1;
            }
            else 
            {
                lo = mid + 1;
            }
        }
        return ans;
    }
};