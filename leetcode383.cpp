class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size();
        unordered_map<char,int> mp;
        for(int i = 0; i < magazine.size(); i++){
            mp[magazine[i]]++;
        }
        for(int i = 0; i < n; i++){
            if(mp.find(ransomNote[i]) != mp.end()) {
                if(mp[ransomNote[i]] == 0) return false;
                else mp[ransomNote[i]]--;
            }
            else return false;
        }

        return true;
    }
};