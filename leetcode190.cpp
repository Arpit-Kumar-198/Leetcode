class Solution {
public:
int decimal(string s){
    int res = 0;
    int d = 0;
    for(int i = s.size()-1; i >= 0; i--){
        if(s[i] == '1') res += pow(2,d);
        d++;
    }
    return res;
}
    int reverseBits(int n) {
        string s = "";
        while(n > 0){
            if(n%2 == 0) s += "0";
            else s += "1";
            n /= 2;
        }
        if(s.size() != 32){
            while(s.size() != 32){
                s += "0";
            }
        }
        
        return decimal(s);
    }
};