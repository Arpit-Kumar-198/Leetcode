class Solution {
public:
bool containZero(int n){
    while(n > 0){
        if((n%10) == 0) return true;
        n /= 10;
    }
    return false;
}
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans(2,0);
        ans[0] = 1, ans[1] = n-1;

        int c = 1;
        while(containZero(ans[0]) || containZero(ans[1])){
            ans[0]++;
            ans[1]--;
        }
        return ans;
    }
};