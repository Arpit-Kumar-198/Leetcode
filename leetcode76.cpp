class Solution {
public:
bool compare(unordered_map<char,int>& mp1, unordered_map<char,int>& mp2){
    for(auto it : mp2){
        if(mp1[it.first] < it.second)
            return false;
    }
    return true;
}
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if(m < n) return "";
        unordered_map<char,int> mp1, mp2;
        for(auto ch : t) mp2[ch]++;

        int i = 0, j = 0, sidx = -1, eidx = -1, ans = INT_MAX;
        while(j < m && i < m){
            if(mp2.count(s[j])) mp1[s[j]]++;
            
            if(compare(mp1,mp2)){
                while(i < m && compare(mp1,mp2)){
                    if(j-i+1 < ans){
                        sidx = i;
                        eidx = j;
                        ans = j-i+1;
                    }
                    if(mp2.count(s[i])) mp1[s[i]]--;
                    if(mp1[s[i]] == 0) mp1.erase(s[i]);
                    i++;
                }
                while(i < m && mp2.count(s[i]) == 0) i++;
            }
            j++;
        }
        if(sidx != -1 && eidx != -1) return s.substr(sidx, ans);
        return "";
    }
};