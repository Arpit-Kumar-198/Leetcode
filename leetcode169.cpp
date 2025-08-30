class Solution {
public:
/*
    Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n==1) return nums[0];
        else if(n%2 == 0) return nums[n/2-1];
        else return nums[n/2];
        return 0;
    }
};