class Solution {
public:

int dfs(int node,unordered_map<int,vector<int>>&adj, vector<bool>&hasApple,vector<bool>&visited){

    visited[node] = true;
    int time = 0;
    for(auto &ngbr : adj[node]){
        if(!visited[ngbr]){
            
        int time_from_child = dfs(ngbr,adj,hasApple,visited);

        if(time_from_child > 0 || hasApple[ngbr]){
            time += (2 + time_from_child);
        }
    }
    

    
    }
    return time;
}
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int m = edges.size();
        unordered_map<int,vector<int>>adj;
        for(int i = 0; i < m; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>visited(n,false);
        return dfs(0,adj,hasApple,visited);
    

    }
};