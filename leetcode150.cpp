class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++){
                if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "/" && tokens[i] != "*") st.push(stoi(tokens[i]));
                else {
                    int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();
                    if(tokens[i] == "+") st.push(a+b);
                    if(tokens[i] == "-") st.push(a-b);
                    if(tokens[i] == "/") st.push(a/b);
                    if(tokens[i] == "*") st.push(a*b);
                }
        }
        return st.top();
    }
};