class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());

        string f = strs[0], l = strs[strs.size()-1];
        string res = "";
        int i = 0;
        while(i < min(f.size(), l.size()) && f[i] == l[i]){
            res += f[i];
            i++;
        }
        return res;
    }
};