class Solution {
public:
void dfs(int node,unordered_map<int,list<int>>&adj,unordered_map<int,bool>&visited, int &nodes, int &degreesum){
    visited[node] = true;
    nodes++;
    degreesum += adj[node].size();
    for(auto v : adj[node]){
        if(!visited[v]){
            dfs(v, adj, visited, nodes, degreesum);
        }
    }
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,list<int>>adj;
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int,bool>visited;
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                int nodes =0;
                int degreesum = 0;
                dfs(i, adj, visited, nodes, degreesum);
                if(degreesum == nodes * (nodes- 1)) ans++;
            }
        }
        return ans;
    }
};