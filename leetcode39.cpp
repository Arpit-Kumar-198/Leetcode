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
void combination(vector<int> v, vector<int> ans, int n, int target){
    if(target == 0)
    {
         for(int i = 0; i < ans.size(); i++) cout << ans[i];
         cout << endl;
         return;
    }
    if(target < 0) return;
   for(int i = 0; i < n; i++)
   {
    ans.push_back(v[i]);
    combination(v,ans,n,target-v[i]);
    ans.pop_back();
   }
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
    vector<int> ans;
    combination(v,ans,n,target);
    return 0;
}