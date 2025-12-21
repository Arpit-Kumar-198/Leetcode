class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        for(auto ch : text) mp[ch]++;
        int mn = INT_MAX;
        if(mp.count('a') && mp.count('b') && mp.count('n')) mn = min(mp['a'],min(mp['b'],mp['n']));
        else return 0;

        int cnt = 0, lcnt = 0, ocnt = 0;
        if(mp.count('l') && mp.count('o')){
            lcnt = mp['l'];
            ocnt = mp['o'];
        }
        else return 0;

        int secmn = min(lcnt,ocnt);
        secmn /= 2;

        if(secmn < mn) return secmn;
        else if(secmn == mn) return mn;
        return mn;

    }
};