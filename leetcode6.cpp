class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int n = s.size();
        
        string res = "";

        int y = ( numRows - 2 )*2;

        for(int i = 0; i < numRows; i++){
            if(i == 0 || i == numRows-1) {
                int x = numRows + (numRows - 2);
                int j = i;
                while(j < n){
                    res += s[j];
                    j += x;
                }
            }
            else{
                int x = numRows + (numRows - 2);
                int j = i;
                int t = j;
                while(j < n){
                    res += s[j];
                    j += y;
                    if(j < n) res += s[j];
                    j = t + x;
                    t = j;
                }
                y -= 2;
            }
        }

        return res;
        
    }
};