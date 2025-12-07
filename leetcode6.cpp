class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string res = "";
        int fl = 2*numRows - 2;
        int m1 = 2*numRows - 4, m2 = 2;
        for(int i = 0; i < s.size(); ) {
            res += s[i];
            i += fl;
        }
        for(int i = 1; i < numRows-1; i++){
            int j = i;
            int turn = 0;
            while(j < s.size()){
                res += s[j];
                if(turn == 0) {
                    j += m1;
                    turn = 1;
                }
                else {
                    j += m2;
                    turn = 0;
                }
            }
            m1 -= 2, m2 += 2;
        }
        for(int i = numRows-1; i < s.size(); ) {
            res += s[i];
            i += fl;
        }
        return res;
    }
};