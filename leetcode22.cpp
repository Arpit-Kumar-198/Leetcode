// famous interview question
/*
    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
*/
class Solution {
public:
void helper(vector<string>& ans, string s, int n, int o, int c)
{
    if(o==n && c==n) 
    {
        ans.push_back(s);
        return;
    }
  
       if(o < n) helper(ans,s+"(",n,o+1,c);
        if(c < o) helper(ans,s+")",n,o,c+1);
        return;

}
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        helper(v,"",n,0,0);
        return v;
    }
};