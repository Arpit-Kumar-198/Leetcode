class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(101,0);
        for(int i=0; i<n; i++){
            arr[nums[i]]++;
        }
        int mx = arr[0];
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>mx) mx=arr[i];
        }
        int cnt = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]==mx) cnt++;
        }
        return cnt*mx;
        
    }
};