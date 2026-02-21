class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int ans = 0, i = 0, j = 0;
        while(i < s.size() && j < s.size()){
            mp[s[j]]++;
            
            while(i < s.size() && mp[s[j]] > 1) {
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};