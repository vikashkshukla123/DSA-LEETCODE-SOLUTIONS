class Solution {
public:
long long dfs(int node, int n, vector<int>&baseTime, unordered_map<int,vector<int>>&adj,vector<long long>&dp){
    if(adj.find(node) == adj.end()){
        return baseTime[node];
    }
    if(dp[node] != -1){
        return dp[node];
    }

    long long mini = 1e18;
    long long maxi = -1e18;

    for(auto &ngbr : adj[node]){
        mini = min(mini,dfs(ngbr,n,baseTime,adj,dp));
        maxi = max(maxi,dfs(ngbr,n,baseTime,adj,dp));
    }


    return dp[node] =  (maxi - mini + baseTime[node] + maxi);


    
}
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        unordered_map<int,vector<int>>adj;
        vector<long long>dp(n,-1);
        int m = edges.size();
        for(int i = 0; i < m; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);

            
        }
        return dfs(0,n,baseTime,adj,dp);
    }
};
