class Solution {
public:
int precedence(char ch){
    if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    return 0;
}
int evaluate(string s){
    int i = 0;
    stack<int> st;
    string temp = "";
    while(i < s.size()){
        if(s[i] == '('){
            i++;
            while(i < s.size() && s[i] != ')') {
                temp += s[i];
                i++;
            }
            st.push(stoi(temp));
            temp = "";
        }
        else {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if(s[i] == '+') st.push(a+b);
            if(s[i] == '-') st.push(a-b);
            if(s[i] == '/') st.push(a/b);
            if(s[i] == '*') st.push(a*b);
        }
        i++;
    }
    return st.top();
}
string postfix(string s){
    string postfixExp = "";
    stack<char> st;
    int i = 0;
    string temp = "";
    while(i < s.size()){
        if(s[i]!='+' && s[i]!='-' && s[i]!='/' && s[i]!='*') temp+=s[i];
        else{
            postfixExp += "("+temp+")";
            temp = "";
            while(!st.empty() && precedence(st.top()) >= precedence(s[i])) {
                postfixExp += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    if(temp != "") postfixExp += "("+temp+")";
    while(!st.empty()) {
        postfixExp += st.top();
        st.pop();
    }
    return postfixExp;
}
    int calculate(string s) {
        string temp = "";
        for(int i = 0; i < s.size(); i++) if(s[i] != ' ') temp += s[i];
        return evaluate(postfix(temp));
    }
};