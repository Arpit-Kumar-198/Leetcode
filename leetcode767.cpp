class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        char major = ' ';
        int majorTotal = 0;
        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
            if(mp[s[i]] > majorTotal){
                majorTotal = mp[s[i]];
                major = s[i];
            }
        }

        int t = n%2 == 0 ? n : n+1;
        if(majorTotal > t/2) return "";
        
        string ch(n,'*');
        int i = 0;
        while(i < n && mp[major]){
            ch[i] = major;
            mp[major]--;
            i += 2;
        }
        mp.erase(major);
        if(i >= n) i = 1;

        priority_queue< pair<char,int> > pq;
        for(auto it : mp){
            pq.push({it.first,it.second});
        }
        while(!pq.empty()){
            pair<char,int> x = pq.top();
            pq.pop();

            while(x.second){
                if(ch[i%n] == '*'){
                    ch[i%n] = x.first;
                    x.second--;
                    i += 2;
                }
                else i++;
            }

        }
        
        return ch;
    }
};