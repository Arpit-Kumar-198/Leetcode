class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        unordered_map<char,int> mp;
        int mxlen = -1;
        
        int i = 0, j = 0;
        while(j < n){
            if(mp.find(s[j]) != mp.end()){
                if(mp.size() <= k) {
                    mp[s[j]]++;
                    j++;
                }
            }
            else{
                if(mp.size() < k){
                    mp[s[j]]++;
                    j++;
                }
                else{
                    mxlen = max(mxlen,j-i);
                    while(mp.size() >= k){
                        mp[s[i]]--;
                        if(mp[s[i]] == 0) mp.erase(s[i]);
                        i++;
                    }
                }
            }
        }
        
        if(mp.size() >= k){
            mxlen = max(mxlen,j-i);
        }
        
        return mxlen;
    }
};