class Solution {
public:
    bool checkAlmostEquivalent(string s1, string s2) {
        unordered_map<char, int> mp1, mp2;
        for (int i = 0; i < s1.size(); i++) mp1[s1[i]]++;
        for (int i = 0; i < s2.size(); i++) mp2[s2[i]]++;

        bool flag = true;
        for(auto it : mp1){
            if(mp2.count(it.first)){
                int f1 = it.second, f2 = mp2.find(it.first)->second;
                if (abs(f1-f2) > 3) flag = false;
            }
            else{
                if(it.second > 3) flag = false;
            }
        }
        for(auto it : mp2){
            if(mp1.count(it.first)){
                int f1 = it.second, f2 = mp1.find(it.first)->second;
                if (abs(f1-f2) > 3) flag = false;
            }
            else{
                if(it.second > 3) flag = false;
            }
        }
        return flag;
    }
};