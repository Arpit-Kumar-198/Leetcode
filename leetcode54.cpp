class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int sr = 0, er = m-1, sc = 0, ec = n-1; 
        vector<int> res(m*n,-101);
        int cnt = 0, idx = 0, tne = m*n;
        while(cnt < tne){
            for(int i = sc; i <= ec && cnt < tne; i++){
                res[idx++] = matrix[sr][i];
                cnt++;
            }
            sr++;
            for(int i = sr; i <= er && cnt < tne; i++){
                res[idx++] = matrix[i][ec];
                cnt++;
            }
            ec--;
            for(int i = ec; i >= sc && cnt < tne; i--){
                res[idx++] = matrix[er][i];
                cnt++;
            }
            er--;
            for(int i = er; i >= sr && cnt < tne; i--){
                res[idx++] = matrix[i][sc];
                cnt++;
            }
            sc++;
        }
        return res;
    }
};