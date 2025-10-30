class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int f = INT_MAX;
        int s = INT_MAX;

        for(auto it : nums){
            if(it <= f) f = it;
            else if(it <= s) s = it;
            else return true;
        }
        return false;
    }
};