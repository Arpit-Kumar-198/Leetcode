class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        if(s.size() != t.size()) return false;
        for(int i = 0; i < s.size(); i++){
            if(mp.find(s[i]) != mp.end()){
                if(mp[s[i]] != t[i]) return false;
            }
            else mp[s[i]] = t[i];
        }
        mp.clear();
        for(int i = 0; i < t.size(); i++){
            if(mp.find(t[i]) != mp.end()){
                if(mp[t[i]] != s[i]) return false;
            }
            else mp[t[i]] = s[i];
        }
        return true;
    }
};