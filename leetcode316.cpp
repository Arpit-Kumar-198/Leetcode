class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        unordered_map<char,pair<int,bool>> mp;
        for(int i = 0; i < n; i++) mp[s[i]] = {i,false};
        string ans = "";
        stack<char> st;
        for(int i = 0; i < n ; i++){
            if(st.empty()) {
                st.push(s[i]);
                mp[s[i]].second = true;
            }
            else if(st.top() < s[i]) {
                if(mp[s[i]].second == false){
                    st.push(s[i]);
                    mp[s[i]].second = true;
                }
            }
            else if(st.top() == s[i]) continue;
            else{
                
                while(!st.empty() && mp[st.top()].first > i && st.top() > s[i]) {
                    if(mp[s[i]].second == false){
                        mp[st.top()].second = false;
                        st.pop();
                    }
                    else break;
                }
                if(mp[s[i]].second == false) {
                    st.push(s[i]);
                    mp[s[i]].second = true;
                }
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};