class Solution {
public:
    void sortColors(vector<int>& nums) {
        // dutch flag algo
        int n = nums.size();

        int lo = 0, mid = 0, hi = n-1;
        while(mid <= hi)
        {
            if(nums[mid]==2)
            {
                swap(nums[mid],nums[hi]);
                hi--;
            }
            else if(nums[mid]==0)
            {
                swap(nums[lo],nums[mid]);
                lo++;
                mid++;
            }
            else mid++;
        }
        return;
    }
};