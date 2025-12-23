class Solution {
public:
int countSum(int n){
    int sum = 0;
    while(n > 0){
        int d = n%10;
        sum += (d*d);
        n /= 10;
    }
    return sum;
}
    bool isHappy(int n) {
        unordered_set<int> st;
        st.insert(n);
        while(n != 1){
            int x = countSum(n);
            if(x != 1) {
                if(st.count(x)) return false;
                else {
                    n = x;
                    st.insert(n);
                }
            }
            else return true;
        }
        return true;
    }
};