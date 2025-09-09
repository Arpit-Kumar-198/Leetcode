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

        
    }
};