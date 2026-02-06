class Solution {
public:
    string removeStars(string s) {
        stack<char> s1,s2;
        for(int i = s.size()-1; i >= 0; i--) s1.push(s[i]);
        while(!s1.empty()){
            char ch = s1.top();
            s1.pop();
            if(ch != '*'){
                if(s2.size()==0) s2.push(ch);
                else {
                    if(s2.top()=='*') s2.pop();
                    else s2.push(ch);
                }
            }
            else{
                if(s2.size()==0) s2.push(ch);
                else{
                    if(s2.top()!='*') s2.pop();
                    else s2.push(ch);
                }
            }
        }
        string res ="";
        while(!s2.empty()){
            res += s2.top();
            s2.pop();
        }
        reverse(res.begin(),res.end());
        return res; 
    }
};