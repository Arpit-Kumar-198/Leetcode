class Solution {
public:
/*
    Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        int lo = 0, hi = nums.size()-1;
        while(lo <= hi)
        {
            int mid = (lo+hi)/2;
            if(nums[mid] == target)
            {
                if(mid == 0)
                {
                    res[0] = mid;
                    break;
                }
                else if(nums[mid-1] == target) hi = mid - 1;
                else 
                {
                    res[0] = mid;
                    break;
                }
            }
            else if(nums[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
    int low2 = 0, high2 = nums.size()-1;
    while(low2 <= high2)
    {
        int mid2 = (low2+high2)/2;
        if(nums[mid2] == target)
        {
            res[1] = mid2;
            low2 = mid2+1;
           }
        else if(nums[mid2] < target) low2 = mid2 + 1;
        else high2 = mid2 - 1;
    }
    
        return res;
    }
};