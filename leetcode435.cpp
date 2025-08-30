bool cmp(vector<int>& a1, vector<int>& a2){
    if(a1[1] < a2[1]) return true;
    else return false;
}
class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(),intervals.end(),cmp);
        int s = intervals[0][0];
        int e = intervals[0][1];

        int cnt = 0;
        for(int i = 1; i < n; i++){
            if(intervals[i][0] < e){
                cnt++;
            }
            else{
                s = intervals[i][0];
                e = intervals[i][1];
            }
        }
        return cnt;
    }
};