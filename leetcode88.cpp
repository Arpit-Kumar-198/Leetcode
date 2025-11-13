class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // int i = 0, j = 0, k = 0;
        // vector<int> temp(m+n);
        // while(i < m && j < n)
        // {
        //     if(nums1[i] < nums2[j])
        //     {
        //         temp[k] = nums1[i];
        //         i++,k++;
        //     }
        //     else
        //     {
        //         temp[k] = nums2[j];
        //         j++,k++;
        //     }
        // }
        // if(i == m)
        // {
        //     while(j < n)
        //     {
        //         temp[k] = nums2[j];
        //         j++,k++;
        //     }
        // }
        // if(j == n)
        // {
        //     while(i < m)
        //     {
        //         temp[k] = nums1[i];
        //         i++,k++;
        //     }
        // }
        // nums1.clear();
        // nums1 = temp;
        int i = m-1, j = n-1, idx = m+n-1;
      
        while(j>=0 && i>=0){
            if(nums1[i]<nums2[j]){
                nums1[idx] = nums2[j];
                j--,idx--;
            }
            else{
                nums1[idx] = nums1[i];
                i--,idx--;
            }
        }
        if(i==-1){
            for(int k = 0; k <= j; k++) nums1[k] = nums2[k];
        }
    }
};