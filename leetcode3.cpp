class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        int i = 0, j = 0;
        unordered_set<char> st;
        while(j < n){
            if(st.find(s[j]) == st.end()){
                st.insert(s[j]);
                j++;
            }
            else{
                ans = max(ans,j-i);
                st.erase(s[i]);
                i++;
            }
        }
        ans = max(ans,j-i);
        return ans;
    }
};