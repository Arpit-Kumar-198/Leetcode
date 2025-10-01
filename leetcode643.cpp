class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefix(n);
        prefix[0] = nums[0];
        int pre = prefix[0];
        for(int i = 1; i < n; i++){
            prefix[i] = nums[i]+pre;
            pre = prefix[i];
        }   

        double mxavg = (prefix[k-1])/((double)k);

        int i = 1, j = k;
        while(j < n){
            double avg = (prefix[j]-prefix[i-1])/((double)k);
            mxavg = max(mxavg,avg);
            i++,j++;
        }
        return mxavg;
    }
};