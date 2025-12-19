class Solution {
public:
    int reverseBits(int n) {
        int x = 31, res = 0, lsb = 1;
        while(x){
            int temp = lsb & n;
            temp = temp << x;
            res = res | temp;
            x--;
            lsb = 1;
            n = n >> 1;
        }
        return res;
    }
};