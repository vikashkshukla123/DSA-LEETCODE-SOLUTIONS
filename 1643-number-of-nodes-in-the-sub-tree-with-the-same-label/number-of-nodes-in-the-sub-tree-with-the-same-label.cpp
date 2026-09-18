class Solution {
public:
vector<int>result;
vector<int>solve(int node, unordered_map<int,vector<int>>&adj,string &labels,vector<bool>&visited){
    visited[node] = true;
    vector<int>ans(26,0);
    int idx = labels[node] - 'a';
    ans[idx]++;

    for(auto &ngbr : adj[node]){
        if(!visited[ngbr]){

            vector<int>res = solve(ngbr,adj,labels, visited);

            for(int i = 0; i < 26; i++){
                int cnt = res[i];
                ans[i] += cnt;
                
            }


        }
    }
    result[node] = ans[labels[node] - 'a'];
    return ans;

   
}
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        result.resize(n,0);
        int m = edges.size();
        unordered_map<int,vector<int>>adj;
        for(int i = 0; i < m; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,0);
        vector<int>ans = solve(0,adj,labels,visited);

        return result;
        
    }
};