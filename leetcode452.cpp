bool cmp(vector<int>& a1, vector<int>& a2){
    if(a1[1] < a2[1]) return true;
    else return false;
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end(),cmp);
        int s = points[0][0];
        int e = points[0][1];

        int cnt = 0;
        for(int i = 1; i < n; i++){
            if(points[i][0] > e){
                cnt++;
                s = points[i][0];
                e = points[i][1];
            }
        }
        return cnt+1;

    }
};