class Solution {
public:
int ans = 0;
void dfs(int node, unordered_map<int,unordered_set<int>>&adj, vector<bool>&visited,unordered_map<int,vector<int>>&adj2){
    visited[node] = true;
    for(auto &ngbr : adj2[node]){
        if(!visited[ngbr]){
            if(adj[node].find(ngbr) != adj[node].end()){
                ans++;
            }
            dfs(ngbr,adj,visited,adj2);
        }
        
    }

    return;
}
    int minReorder(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        unordered_map<int,unordered_set<int>>adj;
        unordered_map<int,vector<int>>adj2;
        for(int i = 0; i < m; i++){
            adj[connections[i][0]].insert(connections[i][1]);
            adj2[connections[i][0]].push_back(connections[i][1]);
            adj2[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool>visited(n,false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i,adj,visited,adj2);
            }

        }
        return ans;
    }
};