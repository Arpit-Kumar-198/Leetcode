class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        int a = 0;
        int b = 1;
        int c = 1;
        int sum = a+b+c;
        for(int i = 3; i < n; i++){
            a = b;
            b = c;
            c = sum;
            sum = a+b+c;
        }
        
        return sum;
    }
};