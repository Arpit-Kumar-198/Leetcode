class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int i = 0, j = 0, temp = maxCost, cnt = 0;
        while(j < n){
            if(abs(s[j]-t[j]) <= temp){
                temp -= abs(s[j]-t[j]);
                cnt = max(cnt,j-i+1);
            }
            else{
                while(i < n && temp < abs(s[j]-t[j])){
                    temp += (abs(s[i]-t[i]));
                    i++;
                }
                if(abs(s[j]-t[j]) <= temp){
                    temp -= abs(s[j]-t[j]);
                    cnt = max(cnt,j-i+1);
                }
            }
            j++;
        }
        return cnt;
    }
};