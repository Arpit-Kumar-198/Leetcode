class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n);
        prefix[0] = arr[0];
        for(int i = 1; i < n; i++) prefix[i] = arr[i]+prefix[i-1];
        int ans = 0;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j+=2){
                if(i == 0) sum += prefix[j];
                else sum += (prefix[j]-prefix[i-1]);
            }
            ans += sum;
        }
        return ans;
    }
};