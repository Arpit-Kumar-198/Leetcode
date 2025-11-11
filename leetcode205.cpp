class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<int,int> mp;
        for(int i = 0; i < s.size(); i++){
            mp[(int)s[i]] = -1;
        }

        for(int i = 0; i < s.size(); i++){
            if(mp[(int)s[i]] != -1){
                if((int)t[i] != mp[(int)s[i]]) return false;
            }
            else {
                mp[(int)s[i]] = (int)t[i];
            }
        }

        unordered_map<int,int> mp2;
        for(int i = 0; i < t.size(); i++){
            mp2[(int)t[i]] = -1;
        }

        for(int i = 0; i < t.size(); i++){
            if(mp2[(int)t[i]] != -1){
                if((int)s[i] != mp2[(int)t[i]]) return false;
            }
            else {
                mp2[(int)t[i]] = (int)s[i];
            }
        }

        return true;
    }
};