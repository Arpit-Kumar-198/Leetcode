class Solution {
public:
char findChar(unordered_map<char,int>& mp){
    char ch = ' ';
    int freq = 0;
    for(auto it : mp){
        if(it.second > freq){
            freq = it.second;
            ch = it.first;
        }
    }
    return ch;
}
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char,int> mp;
        int i = 0, j = 0, mxlen = 0;
        while(j < n){
            mp[s[j]]++;
            int length = j-i+1, freq = mp[findChar(mp)];
            while(length - freq > k){
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
                length--;
                freq = mp[findChar(mp)];
            }
            mxlen = max(mxlen,length);
            j++;
        }
        return mxlen;
    }
};