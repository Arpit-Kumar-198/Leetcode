class Solution {
    public:
    /*
        3396. Minimum Number of Operations to Make Elements in Array Distinct
Solved
Easy
Topics
Companies
Hint
You are given an integer array nums. You need to ensure that the elements in the array are distinct. To achieve this, you can perform the following operation any number of times:

Remove 3 elements from the beginning of the array. If the array has fewer than 3 elements, remove all remaining elements.
Note that an empty array is considered to have distinct elements. Return the minimum number of operations needed to make the elements in the array distinct.
    */
        int minimumOperations(vector<int>& nums) {
            int n = nums.size();
            int op = 0;
            for(int i = 0; i < n-1; i++){
                int c = 0;
                for(int j = i+1; j < n; j++){
                    if(nums[j]==nums[i]){
                        c = 1;
                        break;
                    }
                }
    
                if(c==1){
                    if((i+1)%3 == 0) {
                        op = (i+1)/3;
                    }
                    else{
                         op = (i+1)/3 + 1;
                         i = i%3 + i;
                    }
                }
             
            }
            return op;
      }
    };