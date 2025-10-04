class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ans = INT_MIN;
        int cnt = 0;

        unordered_map<int,int> mp;
        
        int i = 0, j = 0;
        while(j < n){
            if(mp.find(fruits[j]) == mp.end()){
                if(cnt == 2){
                    ans = max(ans,j-i);
                    while(mp[fruits[i]] != 0){
                        mp[fruits[i]]--;
                        if(mp[fruits[i]] == 0) break;
                        i++;
                    }
                    mp.erase(fruits[i]);
                    mp[fruits[j]]++;
                    i++,j++;
                }
                else {
                    mp[fruits[j]]++;
                    j++,cnt++;
                }
            }
            else{
                mp[fruits[j]]++;
                j++;
            }
        }
        ans = max(ans,j-i);
        
        return ans;
    }
};