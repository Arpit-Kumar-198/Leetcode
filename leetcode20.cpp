class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i = 0;
        
        while(i < s.size()){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
                i++;
            }
            else{
                    if(st.empty() == true || (s[i] == ')' && st.top() != '(')
                    || (s[i] == '}' && st.top() != '{')
                    || (s[i] == ']' && st.top() != '['))
                    return false;

                    else {
                        st.pop();
                        i++;
                    }
                }
            }
        if(st.size() > 0) return false;
        return true;
    }
};