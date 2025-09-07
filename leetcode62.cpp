class Solution {
public:
// int findPath(int sr, int er, int sc, int ec, vector< vector<int> >& dp){
//     if(sr > er || sc > ec) return 0;
//     if(sr == er && sc == ec) return 1;


//     if(dp[sr][sc] != -1) return dp[sr][sc];
//     return dp[sr][sc] = findPath(sr+1, er, sc, ec,dp) + findPath(sr,er,sc+1,ec,dp);

// }
    int uniquePaths(int m, int n) {
        /* Recursion + Memoization */
        
        // vector< vector<int> > dp(m, vector<int>(n,-1));
        // return findPath(0,m-1,0,n-1,dp);

    
        /* Tabulation method */
        vector< vector<int> > dp(m,vector<int>(n,-1));

        for(int j = 0; j < n; j++) dp[0][j] = 1;
        for(int i = 0; i < m; i++) dp[i][0] = 1;

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];

    }
};