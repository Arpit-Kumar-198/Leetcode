#include<iostream>
#include<vector>
using namespace std;
void combination(vector<int> v, vector<int> ans, int n, int target, int idx){
    if(target == 0)
    {
         for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
         cout << endl;
         return;
    }
    if(target < 0) return;
   for(int i = idx; i < n; i++)
   {
    ans.push_back(v[i]);
    combination(v,ans,n,target-v[i],i);
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
    combination(v,ans,n,target,0);
    return 0;
}