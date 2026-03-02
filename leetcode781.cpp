class Solution {
public:
    int numRabbits(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> m;   // value freq
        for(int i = 0; i < n; i++) m[arr[i]]++;

        int cnt = 0;
        for(auto it : m){
            int val = it.first;
            int freq = it.second;
            int modulus = freq%(val+1);
            if(modulus == 0) cnt += (freq/(val+1))*(val+1);
            else{
                cnt += (freq/(val+1))*(val+1) + (val+1);
            }
        }
        return cnt;
    }
};
