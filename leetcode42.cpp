class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pre(n);
        pre[0] = -1;
        int premx = height[0];
        for(int i = 1; i < n; i++){
            pre[i] = premx;
            if(height[i] > premx) premx = height[i];
        }
        pre[n-1] = -1;
        int postmx = height[n-1];
        for(int i = n-2; i >= 0; i--){
            pre[i] = min(postmx,pre[i]);
            if(height[i] > postmx) postmx = height[i];
        }

        int ans = 0;
        for(int i = 1; i < n-1; i++){
            if(height[i] < pre[i]) ans += (pre[i]-height[i]);
        }
        return ans;
    }
};