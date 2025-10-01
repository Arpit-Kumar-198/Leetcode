class Solution {
public:
bool ispresent(char ch, string s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ch) return true;
    }
    return false;
}
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        // if(n == 0) return 0;
        
        // int mxlen = INT_MIN;
        // for(int i = 0; i < n; i++){
        //     int j = i;
        //     string t = "";
        //     while(j < n && ispresent(s[j],t) == false){
        //         t += s[j];
        //         mxlen = max(mxlen,(int)t.size());
        //         j++;
        //     }

        // }
        // return mxlen;

        if(n == 0) return 0;
        unordered_map<char,bool> mp;
        for(int i = 0; i < n; i++){
            mp[s[i]] = false;
        }
        int mxlen = INT_MIN;
        int i = 0, j = 0;

        while(j < n){
            if(mp.find(s[j]) != mp.end()){
                if(mp[s[j]] == true){
                    mxlen = max(mxlen,j-i);
                    mp[s[i]] = false;
                    i++;
                }
                else{
                    mp[s[j]] = true;
                    j++;
                }
            }
        }
        mxlen = max(mxlen,j-i);
        return mxlen;
    }
};