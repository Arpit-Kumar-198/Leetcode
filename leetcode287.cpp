class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // O(1) space complexity and O(n) time complexity
        int slow = nums[0], fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        }while(slow != fast);

        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};