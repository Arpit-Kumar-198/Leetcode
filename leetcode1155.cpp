class Solution {
public:
const int mod = 1000000000+7;
int helper(int n, int k, int tgt, vector< vector<int> >& dp){
    if(n == 0 && tgt == 0) return 1;
    if(n == 0 && tgt > 0 || tgt < 0) return 0;
    int sum = 0;
    if(dp[n][tgt] != -1) return dp[n][tgt];
    for(int i = 1; i <= k; i++){
        int x = helper(n-1,k,tgt-i,dp);
        sum = (sum%mod + x%mod)%mod;
    }
    return dp[n][tgt] = sum%mod;
    
}
    int numRollsToTarget(int n, int k, int target) {
        vector< vector<int> > dp(n+1, vector<int> (target+1,-1));
        return helper(n,k,target,dp);
    }
};