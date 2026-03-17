class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int i = 1, j = k, sum = 0, cnt = 0;
        for(int i = 0; i < k; i++) sum += arr[i];
        if(sum >= threshold*k) cnt++;
        while(j < n){
            sum = sum - arr[i-1] + arr[j];
            if(sum >= threshold*k) cnt++;
            i++,j++;
        }
        return cnt;
    }
};