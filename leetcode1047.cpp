class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        stack<char> st2;
        for(char ch : s) st.push(ch);
        string ans = "";
    
        st2.push(st.top());
        st.pop();
        
        while(!st.empty()){
            if(st2.empty()) {
                st2.push(st.top());
                st.pop();
            }
            else if(st.top() != st2.top()){
                st2.push(st.top());
                st.pop();
            }
            else{
                st.pop();
                st2.pop();
            }
        }
        while(!st2.empty()){
            ans += st2.top();
            st2.pop();
        }
        return ans;
    }
};