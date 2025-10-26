class Solution {
public:
int helper(int idx, vector<int>& prices, bool allow,vector< vector<int> >& dp){
    int profit = 0;
    if(idx >= prices.size()) return 0;
    if(dp[idx][allow] != -1) return dp[idx][allow];
    if(allow){
        int a = (-1)*prices[idx] + helper(idx+1,prices,false,dp);
        int b = 0 + helper(idx+1,prices,true,dp);
        profit = max(a,b);
        dp[idx][1] = profit;
    }
    else{
        int a = prices[idx] + helper(idx+1,prices,true,dp);
        int b = 0 + helper(idx+1,prices,false,dp);
        profit = max(a,b);
        dp[idx][0] = profit;
    }
    return profit;
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector< vector<int> > dp(n, vector<int> (2,-1));
        return helper(0,prices,true,dp);
    }
};