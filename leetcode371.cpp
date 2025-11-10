class Solution {
public:
    int getSum(int a, int b) {
        if(b == 0) return a;
        int sum = a^b;
        int carry = (a & b) << 1; // becoz in addition carry is added to next bit
        return getSum(sum,carry);
    }
};