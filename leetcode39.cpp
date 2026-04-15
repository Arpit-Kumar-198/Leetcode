/*
    Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
*/
#include<iostream>
#include<vector>
using namespace std;
void solve(int idx, int tgt, vector<int>& arr, vector<int>& temp, vector<vector<int>>& ans){
    if(tgt < 0) return;
    if(tgt == 0){
        ans.push_back(temp);
        return;
    }
    for(int i = idx; i < arr.size(); i++){
        temp.push_back(arr[i]);
        solve(i, tgt-arr[i], arr, temp, ans);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> temp;
    vector<vector<int>> ans;
    solve(0, target, candidates, temp, ans);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        v.push_back(c);
    }
    int target;
    cin >> target;
    vector<vector<int>> ans = combinationSum(v, target);
    for(auto vec : ans){
        cout << "[";
        for (int i = 0; i < vec.size(); i++){
            if(i < vec.size()-1) cout << vec[i] << ",";
            else cout << vec[i];
        }
        cout << "]" << endl;
    }
    return 0;
}