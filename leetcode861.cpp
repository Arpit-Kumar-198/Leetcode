class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // making the 1st column all 1.
        for(int i = 0; i < m; i++)
        {
           if(grid[i][0] == 0){
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 0) grid[i][j] = 1;
                else grid[i][j] = 0;
            }
           }
        }
        // flipping the columns where no. of 0s > no. of 1s
        for(int j = 0; j < n; j++)
        {
            int nOz = 0;
            int nOo = 0;
            for(int i = 0; i < m; i++)
            {
                if(grid[i][j] == 0) nOz++;
                else nOo++;
            }
            if(nOz > nOo)
            {
                for(int i = 0; i < m; i++)
              {
                if(grid[i][j] == 0) grid[i][j] = 1;
                else grid[i][j] = 0;
              }
            }
        }
           
        int sum = 0;
        for(int i = 0; i < m; i++)
        {
            int x = 1;
            for(int j = n-1; j >= 0; j--)
            {
                sum += grid[i][j] * x;
                x *= 2;
            }
        }
        return sum;
    }
};