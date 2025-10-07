class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int vol = min(height[n-1],height[0]) * (n-1);
        int idx1 = 0, idx2 = n-1;

        int i = 0, j = n-1;
        while(i < j){
            idx1 = i, idx2 = j;
            vol = max(min(height[idx2],height[idx1]) * (idx2-idx1), vol);
            if(height[i] < height[j]) i++;
            else j--;
        }
        return vol;
    }
};