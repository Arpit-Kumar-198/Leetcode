class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;

        
        if(n1 <= n2){
            for(int i = 0; i < n1; i++) mp1[s1[i]]++;
            int i = 0, j = n1-1;
            for(int i = 0; i < n1; i++) mp2[s2[i]]++;
            while(j < n2){
                if(mp1 == mp2) return true;
                mp2[s2[i]]--;
                if(mp2[s2[i]] == 0) mp2.erase(s2[i]);
                i++,j++;
                if(j < n2) mp2[s2[j]]++;
            }
            return false;
        }
        
        return false;

    }
};
