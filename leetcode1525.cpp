class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        unordered_map<char,int> mp1, mp2;
        for(auto ch : s) mp2[ch]++;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(mp1.size() == mp2.size()) ans++;
            mp2[s[i]]--;
            mp1[s[i]]++;
            if(mp2[s[i]] == 0) mp2.erase(s[i]);
        }
        return ans;
    }
};