class Solution {
public:
void solve(int node, unordered_map<int,vector<int>>&adj,vector<bool>&visited){
    visited[node] = true;
    for(auto &ngbr : adj[node]){
        if(!visited[ngbr]){
            solve(ngbr,adj,visited);
        }
    }
    return;

}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_map<int,vector<int>>adj;
        for(int i = 0; i < n; i++){
            vector<int>room = rooms[i];
            for(int j = 0; j < room.size(); j++){
                adj[i].push_back(room[j]);


            }
        }
        vector<bool>visited(n,false);

        solve(0,adj,visited);

        for(int i = 0; i < visited.size(); i++){
            if(visited[i] == false){
                return false;
            }
        }
       return true; 
    }
};