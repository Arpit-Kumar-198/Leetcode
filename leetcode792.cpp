class Solution {
public:
int findidx(vector<int>& arr, int idx){
    int lo = 0, hi = arr.size()-1, ans = -1;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(arr[mid] > idx) {
            ans = arr[mid];
            hi = mid-1;
        }
        else lo = mid+1;
    }
    return ans;
}
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        unordered_map<char,vector<int>> mp;
        for(int i = 0; i < s.size(); i++) mp[s[i]].push_back(i);
        for(string str : words){
            int idx = -1;
            bool flag = true;
            for(int j = 0; j < str.size(); j++){
                if(mp.find(str[j]) !=  mp.end()){
                    int x = findidx(mp[str[j]],idx);
                    if(x != -1) idx = x;
                    else {
                        flag = false;
                        break;
                    }
                }
                else {
                    flag = false;
                    break;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};