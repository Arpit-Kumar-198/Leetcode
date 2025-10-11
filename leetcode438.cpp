class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();

        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        vector<int> res;
        for(int i = 0; i < n2; i++) mp1[p[i]]++;
        for(int i = 0; i < n2; i++) mp2[s[i]]++;
        
        int i = 0, j = n2-1;
        
        while(j < n1){
            if(mp1 == mp2){
                res.push_back(i);
            }
            mp2[s[i]]--;
            if(mp2[s[i]] == 0) mp2.erase(s[i]);
            i++,j++;
            if(j < n1) mp2[s[j]]++;
        }
        return res;
    }

};