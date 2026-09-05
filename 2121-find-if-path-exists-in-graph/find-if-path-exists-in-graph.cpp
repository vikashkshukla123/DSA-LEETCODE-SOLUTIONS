class Solution {
public:
bool solve(int source, int destination, unordered_map<int,vector<int>>&adj,vector<bool>&visited){
    visited[source] = true;
    if(source == destination){
        return true;
    }
    for(auto &ngbr : adj[source]){
        if(!visited[ngbr]){
            bool solve1 = solve(ngbr,destination,adj,visited);
            if(solve1){
                return true;
            }
        }
    }
    return false;
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
       unordered_map<int,vector<int>>adj;
       for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);

       }
       vector<bool>visited(n,false);
    return solve(source,destination,adj,visited);
        
    }
};