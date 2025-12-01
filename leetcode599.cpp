class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n1 = list1.size(), n2 = list2.size();
        unordered_map<string,int> mp1, mp2;
        for(int i = 0; i < n1; i++) mp1[list1[i]] = i;
        for(int i = 0; i < n2; i++) mp2[list2[i]] = i;
        vector<string> res;
        int sum = INT_MAX;
  
        for(auto it : mp1){
            if(mp2.count(it.first)){
                if(it.second + mp2[it.first] == sum){
                    res.push_back(it.first);
                }
                else if(it.second + mp2[it.first] < sum) {
                    while(!res.empty()){
                        res.pop_back();
                    }
                    sum = it.second + mp2[it.first];
                    res.push_back(it.first);
                }
            }
        }
       
        return res;
    }
};