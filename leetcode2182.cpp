class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> arr(26,0);
        for(int i = 0; i < s.size(); i++) arr[s[i]-'a']++;
        string ans = "";
        int i = 25, j = i;
        char ch1 = 'z';
        int f1 = arr[ch1-'a'];
        while(i >= 0){
            if(f1 == 0) {
                i--,j--;
                if(i >= 0) {
                    ch1 = (char)(i+97);
                    f1 = arr[i];
                }
            }
            if(f1 <= repeatLimit){
                ans += string(f1,ch1);
                f1 = 0;
                arr[ch1-'a'] = 0;
                while(i >= 0 && arr[i] == 0) i--,j--;
                if(i == -1) return ans;
                ch1 = (char)(i+97);
                f1 = arr[i];
            }
            else{
                ans += string(repeatLimit, ch1);
                f1 -= repeatLimit;
                j--;
                while(j >= 0 && arr[j] == 0) j--;
                if(j == -1) return ans;
                ans += string(1,(char)(j+97));
                arr[j]--;
                j = i;
            }
        }
        return ans;
    }
};