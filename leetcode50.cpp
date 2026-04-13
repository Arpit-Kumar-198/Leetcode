class Solution {
public:
    double myPow(double x, int n) {
       if(n == 0) return (double)1;
       double ans = 1;
       long long nn = n;
        if(nn >= 0){
            double temp = myPow(x,nn/2);
            if(nn%2==0) ans = temp*temp;
            else ans = x*temp*temp;
        }
        else{
            double temp = myPow(x,abs(nn)/2);
            if(nn%2==0) ans = 1/(temp*temp);
            else ans = 1/(x*temp*temp);
        }
       return ans;
    }
};