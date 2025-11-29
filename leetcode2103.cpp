class Solution {
public:
    int countPoints(string rings) {
        unordered_map<char, unordered_set<char>> mp;
        for (int i = 1; i < rings.size(); i+=2){
            mp[rings[i]].insert(rings[i-1]);
        }
        int cnt = 0;
        for (auto it : mp)
        {
            if(it.second.size() == 3) cnt++;
        }
        return cnt;
    }
};