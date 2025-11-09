class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string temp;
        vector<string> arr;
        while(ss >> temp){
            arr.push_back(temp);
        }
        string ans = "";
        for(int i = arr.size()-1; i >= 0; i--){
            if(i!=0){
                ans += (arr[i]+" ");
            }
            else{
                ans += arr[i];
            }
        }
        return ans;
    }
};