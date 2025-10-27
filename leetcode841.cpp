class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        queue<int> q;
        q.push(0);
        visited.insert(0);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int neigh : rooms[curr]){
                if(!visited.count(neigh)) {
                    q.push(neigh);
                    visited.insert(neigh);
                }
            }
        }
        if(visited.size() == rooms.size()) return true;
        return false;
    }
};