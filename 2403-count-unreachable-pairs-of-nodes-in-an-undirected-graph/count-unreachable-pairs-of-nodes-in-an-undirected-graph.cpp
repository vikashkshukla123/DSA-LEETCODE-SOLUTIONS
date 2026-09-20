class Solution {
public:
long long dfs(int node, unordered_map<int,vector<int>>&adj, vector<bool>&visited){
    visited[node] = true;
    long long ans = 1;
    for(auto &ngbr : adj[node]){
        if(!visited[ngbr]){
            ans += dfs(ngbr, adj,visited);
        }
    }
    return ans;
}
    long long countPairs(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        unordered_map<int,vector<int>>adj;
        for(int i = 0; i < m; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        long long remaining_nodes = n;
        vector<bool>visited(n,false);
        long long ans = 0;
        for(int i = 0; i < n; i++){
            if(visited[i] == true) continue;
            long long count = dfs(i,adj,visited);
            ans += (count * (remaining_nodes - count));
            remaining_nodes = remaining_nodes - count;
            
        }

        return ans;
        
    }
};