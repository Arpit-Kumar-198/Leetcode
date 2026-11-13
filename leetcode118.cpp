class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector< vector<int> > mat;
        mat.push_back({1});
        if(numRows == 1) return mat;

        vector<int> temp;
        for(int i = 1; i < numRows; i++)
        {
            temp.resize(i+1, 1);
            mat.push_back(temp);
            temp.clear();
        }
        if(numRows == 2) return mat;
        
        for(int i = 2; i < numRows; i++){
            for(int j = 1; j < mat[i].size()-1; j++){
                mat[i][j] = mat[i-1][j] + mat[i-1][j-1];
            }
        }
        return mat;
    }
};