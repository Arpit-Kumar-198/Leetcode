class Solution {
public:
string helper(string original, int k, string ans)
{
    if(original == "") return ans;
    int n = original.size();
    
    int fact = 1;
    for(int i = 2; i <= n-1; i++) fact *= i;
    int idx = k/fact;
    if(k%fact == 0) idx -= 1;
    ans += original[idx];
    string left = "";
    if(idx!=0) left = original.substr(0,idx);
    string right = "";
    if(idx!=n-1) right = original.substr(idx+1);
    int q;
    int t = k/fact;
    if(k%fact == 0) q = fact;
    else q = k-(t*fact);
    return helper(left+right,q,ans);
}
    string getPermutation(int n, int k) {
       string s = "";
       for(int i = 1; i <= n; i++) s += to_string(i);
       return helper(s,k,"");
    }
};