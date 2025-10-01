class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        // vector<int> prefix(n);
        // prefix[0] = nums[0];
        // int pre = prefix[0];
        // for(int i = 1; i < n; i++){
        //     prefix[i] = nums[i]+pre;
        //     pre = prefix[i];
        // }   

        // double mxavg = (prefix[k-1])/((double)k);

        // int i = 1, j = k;
        // while(j < n){
        //     double avg = (prefix[j]-prefix[i-1])/((double)k);
        //     mxavg = max(mxavg,avg);
        //     i++,j++;
        // }
        // return mxavg;


        double mxavg = 0;
        double presum = 0;

        for(int i = 0; i < k; i++){
            presum += nums[i];
        }
        mxavg = presum/k;

        int i = 1, j = k;
        while(j < n){
            double currsum = presum - nums[i-1] + nums[j];
            mxavg = max(mxavg,currsum/k);
            presum = currsum;
            i++,j++;
        }
        return mxavg;
    }
};