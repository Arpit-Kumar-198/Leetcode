class Solution {
public:
void merge(vector<pair<int,int>>& arr, int lo, int hi, int m, vector<int>& res){
    int n1 = m-lo+1;
    int n2 = hi-m;
    vector<pair<int,int>> a1(n1), a2(n2);
    for(int i = 0; i < n1; i++) {
        a1[i] = arr[lo+i];
    }
    for(int i = 0; i < n2; i++) {
        a2[i] = arr[m+1+i];
    }

    int i = 0, j = 0, k = lo;

    while(i < n1 && j < n2){
        if(a1[i].first > a2[j].first){
            arr[k].first = a1[i].first;
            arr[k].second = a1[i].second;
            res[a1[i].second] += (n2-j);
            k++,i++;
        }
        else {
            arr[k].first = a2[j].first;
            arr[k].second = a2[j].second;
            j++,k++;
        }
    }
    while(i < n1){
        arr[k].first = a1[i].first;
        arr[k].second = a1[i].second;
        res[a1[i].second] += (n2-j);
        k++,i++;
    }
    while(j < n2){
        arr[k].first = a2[j].first;
        arr[k].second = a2[j].second;
        k++,j++;
    }
}
void mergeSort(vector<pair<int,int>>& arr, int lo, int hi, vector<int>& res){
    if(lo < hi){
        int m = lo + (hi-lo)/2;
        mergeSort(arr,lo,m,res);
        mergeSort(arr,m+1,hi,res);
        merge(arr,lo, hi, m,res);
    }
}
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        vector<int> res(n,0);

        vector<pair<int,int>> arr(n);

        for(int i = 0; i < n; i++){
            arr[i].first = nums[i];
            arr[i].second = i;
        }
        mergeSort(arr, 0, n-1, res);
        return res;
    }
};