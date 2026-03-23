class Solution {
public:
    bool canPlaceQueen(int row, int col, int n, vector<vector<char>>& grid){
        // column check 
        for(int i = row-1; i >= 0; i--)
            if(grid[i][col] == 'Q') return false;
        // left diagonal check
        for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
            if(grid[i][j] == 'Q') return false;
        // left diagonal check
        for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++)
            if(grid[i][j] == 'Q') return false;
        return true;
    }
    void helper(int row, int n, vector<vector<char>>& grid, vector<vector<string>>& ans){
        if(row == n){
            vector<string> v;
            for(auto &row : grid){
                string temp = "";
                for(auto &ch : row) temp += ch;
                v.push_back(temp);
            }
            ans.push_back(v);
        }
        for(int col = 0; col < n; col++){
            if(canPlaceQueen(row, col, n, grid)){
                grid[row][col] = 'Q';
                helper(row+1, n, grid, ans);
                grid[row][col] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> grid(n, vector<char>(n,'.'));
        vector<vector<string>> ans;
        helper(0, n, grid, ans);
        return ans;
    }
};