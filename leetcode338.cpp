class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        res[0] = 0;
        for(int i = 1; i <= n; i++){
            int d = i/2;
            if(i%2 != 0) res[i] = res[d]+1;
            else res[i] = res[d];
        }
        return res;
    }
};