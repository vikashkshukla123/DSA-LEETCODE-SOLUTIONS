class Solution {
public:
int components = 0;
int solve(int node,unordered_map<int,vector<int>>&adj,vector<int>&values,int k, vector<bool>&visited){
    visited[node] = true;
    int sum = values[node];
    for(auto &ngbr : adj[node]){
        if(!visited[ngbr]){
            sum  += solve(ngbr,adj,values,k,visited);
            sum = (sum % k);
        }
    }
    sum = sum % k;
    if(sum ==  0){
        components++;
        return 0;
    }
    

    return (sum);

}
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int,vector<int>>adj;
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,false);
        solve(0,adj,values,k,visited);
        return components;
    }
};