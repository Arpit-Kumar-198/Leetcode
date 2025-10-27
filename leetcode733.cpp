class Solution {
public:
void helper(vector<vector<int>>& arr, int sr, int sc, int color, int tgt){

    int m = arr.size(), n = arr[0].size();
    if(sr >= m || sc >= n || sr < 0 || sc < 0) return;
    if(arr[sr][sc] == color) return;
    if(arr[sr][sc] != tgt) return;
    
        arr[sr][sc] = color;
    
        helper(arr,sr,sc-1,color,tgt);
        helper(arr,sr,sc+1,color,tgt);
        helper(arr,sr-1,sc,color,tgt);
        helper(arr,sr+1,sc,color,tgt);
    
    return;
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int tgt = image[sr][sc];
        helper(image,sr,sc,color,tgt);
        return image;
    }
}; 