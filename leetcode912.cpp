class Solution {
public:
int partition(vector<int>& nums, int lo, int hi){
    int pivotIdx = lo + rand() % (hi-lo+1);
    swap(nums[pivotIdx], nums[hi]);
    int pivot = nums[hi];

    int i = lo-1;
    for(int j = lo; j <= hi; j++){
        if(nums[j] < pivot){
            i++;
            swap(nums[i],nums[j]);
        }
    }
    swap(nums[hi],nums[i+1]);
    return i+1;
}
void quickSort(vector<int>& nums, int lo, int hi){
    if(lo < hi){
        int p = partition(nums,lo,hi);
        quickSort(nums,lo,p-1);
        quickSort(nums,p+1,hi);
    }
}
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
        return nums;
    }
}; 