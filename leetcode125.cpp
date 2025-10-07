class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i]>='a' && s[i]<='z') ans+=s[i];
            else if(s[i]>='A' && s[i]<='Z'){
                ans += (char)(s[i]+32);
            }
            else if(s[i]>='0' && s[i]<='9') ans+=s[i];
        }
        int i = 0, j = ans.size()-1;
        while(i <= j){
            if(ans[i] != ans[j]) return false;
            i++,j--;
        }
        return true;
    }
};