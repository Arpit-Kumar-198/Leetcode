class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> st;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto n : nums) st.insert(n);
        for(auto n : st) pq.push(n);
        if(pq.size() < 3){
            while(pq.size() != 1) pq.pop();
            return pq.top();
        }
        while(pq.size() != 3) pq.pop();
        return pq.top();
    }
};