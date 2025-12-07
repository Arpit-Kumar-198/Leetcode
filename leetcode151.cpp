class Solution {
public:
    string reverseWords(string s) {
        // stringstream ss(s);
        // string temp;
        // vector<string> arr;
        // while(ss >> temp){
        //     arr.push_back(temp);
        // }
        // string ans = "";
        // for(int i = arr.size()-1; i >= 0; i--){
        //     if(i!=0){
        //         ans += (arr[i]+" ");
        //     }
        //     else{
        //         ans += arr[i];
        //     }
        // }
        // return ans;
        int n = s.size();
        string res = "";
        for(int i = n-1; i >= 0; i--){
            string temp = "";
            if(s[i] != ' '){
                while(i >= 0 && s[i] != ' '){
                    temp = s[i]+temp;
                    i--;
                }
                res += (temp+" ");
            }
        }
        string ans = "";
        for(int i = 0; i < res.size()-1; i++) ans += res[i];
        return ans;
    }
};