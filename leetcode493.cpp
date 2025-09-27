class Solution {
public:
void merge(vector<int>& nums, int lo, int hi, int m, int& res){
    int n1 = m-lo+1;
    int n2 = hi-m;
    vector<int> a1(n1), a2(n2);
    for(int i = 0; i < n1; i++) a1[i] = nums[lo+i];
    for(int i = 0; i < n2; i++) a2[i] = nums[m+1+i];

    int x = 0;
        for (int i = 0; i < n1; i++) {
            while (x < n2 && (long long)a1[i] > 2LL * a2[x]) x++;
            res += x;
        }
    int i = 0, j = 0, k = lo;
    while(i < n1 && j < n2){
        if(a1[i] <= a2[j]){
                nums[k] = a1[i];
                k++,i++;
        }
        else {
            nums[k] = a2[j];
            k++,j++;
        }
    }
    while(i < n1){
        nums[k] = a1[i];
        k++,i++;
    }
    while(j < n2){
        nums[k] = a2[j];
        k++,j++;
    }
}
void mergeSort(vector<int>& nums, int lo, int hi, int& res){
    if(lo < hi){
        int m = lo + (hi-lo)/2;
        mergeSort(nums,lo,m,res);
        mergeSort(nums,m+1,hi,res);
        merge(nums,lo,hi,m,res);
    }
}
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        mergeSort(nums,0,n-1,res);
        return res;
    }

};