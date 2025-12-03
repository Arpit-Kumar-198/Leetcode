class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        int m = prices[0];
        int profit = 0;
        for(int i = 0; i < n; i++){
            m = min(m,prices[i]);
            profit = max(profit,(prices[i]-m));
        }
        return profit;

        // int n = prices.size();
        // int p = 0;

        // int profit = INT_MIN;
        // int tempProfit = 0;

        // for(int i = 0; i < n; i++){
        //     tempProfit = prices[i] - prices[p];
        //     profit = max(profit,tempProfit);
        //     if(tempProfit < 0){
        //         tempProfit = 0;
        //         p = i;
        //     }
        // }
        // return profit;

        
    }
};