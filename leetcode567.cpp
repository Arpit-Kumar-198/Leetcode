class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<int> mp1(26,0);
        vector<int> mp2(26,0);

        
        if(n1 <= n2){
            for(int i = 0; i < n1; i++) mp1[s1[i]-97]++;
            for(int i = 0; i < n1; i++) mp2[s2[i]-97]++;
            int i = 1, j = n1;
            if(mp1 == mp2) return true;
            while(j < n2){
                if(mp2[s2[i-1]-97] != 0) mp2[s2[i-1]-97]--;
                mp2[s2[j]-97]++;
                if(mp1 == mp2) return true;
                i++,j++;
            }
        }
        return false;
    }
};
