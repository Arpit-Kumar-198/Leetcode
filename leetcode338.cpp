class Solution {
public:
int setBit(int n){
    int t = 0;
    while(n > 0){
        if(n%2 != 0) t++;
        n /= 2;
    }
    return t;
}
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for(int i = 0; i <= n; i++){
            res[i] = setBit(i);
        }
        return res;
    }
};