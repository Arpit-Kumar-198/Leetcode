class Solution {
public:
    string minWindow(string s, string t){
        unordered_map<char,int> mp;
        int m = s.size();
        int n = t.size();
        for(int i = 0; i < n; i++) mp[t[i]]++;

        int mnlen = INT_MAX;
        string res = "";
        int idx1 = -1, len = 0;
        int i = 0,j = 0, size = 0;
        while(j < m){

                if(size == n){
                    while(mp.find(s[i]) == mp.end()) i++;
                    if(j-i < mnlen){
                        mnlen = j-i;
                        idx1 = i, len = mnlen;
                    }
                    if(mp[s[i]] == 0) size--;
                    mp[s[i]]++;
                    i++;
                   
                }
                else {
                    if(mp.find(s[j]) != mp.end()){
                        mp[s[j]]--;
                        if(mp[s[j]] >= 0) size++;
                    }
                    j++;
                }
            
            
        }
        while(i < m){
                if(size == n){
                    while(mp.find(s[i]) == mp.end()) i++;
                    if(j-i < mnlen){
                        mnlen = j-i;
                        idx1 = i, len = mnlen;
                    }
                    if(mp[s[i]] >= 0) size--;
                    mp[s[i]]++;
                    i++;
                   
                }
                else i++;
        }
        if(idx1 != -1) res = s.substr(idx1,len);
        return res;
    }
};