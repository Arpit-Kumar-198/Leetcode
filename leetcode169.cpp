class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // return nums[nums.size()/2];

        // unordered_map<int,int> m;
        // for(int i = 0; i < nums.size(); i++){
        //     m[nums[i]]++;
        // }
        // for(auto it : m){
        //     if(it.second > nums.size()/2) return it.first;
        // }
        // return -1;
        if(nums.size() == 1) return nums[0];
        int ele = nums[0];
        int count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(count == 0){
                ele = nums[i];
                count = 1;
            }
            else if(nums[i]==ele) count++;
            else count--;
        }
        return ele;

    }
};