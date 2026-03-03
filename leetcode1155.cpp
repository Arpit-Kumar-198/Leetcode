class Solution {
public:
const int mod = 1000000000+7;
int helper(int n, int k, int tgt, vector< vector<int> >& dp){
    if(n == 0 && tgt == 0) return 1;
    if(n == 0 && tgt > 0) return 0;
    if(dp[n][tgt] != -1) return dp[n][tgt];
    int sum = 0;
    for(int i = 1; i <= k; i++){
        if(tgt-i >= 0) sum = (sum%mod + helper(n-1,k,tgt-i,dp)%mod)%mod;
    }
    return dp[n][tgt] = sum;
    
}
    int numRollsToTarget(int n, int k, int target) {
        vector< vector<int> > dp(n+1, vector<int> (target+1,-1));
        return helper(n,k,target,dp);
    }
};