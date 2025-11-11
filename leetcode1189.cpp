class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        int m = text.size();
        for(int i = 0; i < m; i++) {
            if(text[i] == 'b' || text[i] == 'a' || text[i] == 'l' || text[i] == 'o' || text[i] == 'n') mp[text[i]]++;
        }

        if(mp.size() < 5) return 0;

        int n1 = min(mp['b'],min(mp['a'],mp['n']));
        int n2 = min(mp['l'],mp['o']);

        if(n1*2 == n2) return n1;

        while(n1*2 > n2){
            n1--;
        }
        return n1;
        
    }
};