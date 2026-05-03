class Solution {
public:
vector<vector<int>>result;
int destination_node;
void dfs(int node, vector<int>&ans,vector<bool>&visited,unordered_map<int,vector<int>>&adj){
    visited[node] = true;
    ans.push_back(node);
    if(node == destination_node){
        result.push_back(ans);
        return;
    }

    for(auto & neighbour : adj[node]){
        if(!visited[neighbour]){
            dfs(neighbour,ans,visited, adj);


            visited[neighbour] = false;
            ans.pop_back();
        }
    }
    return;
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>>adj;
        int n = graph.size();
        destination_node = n-1;
        for(int i = 0; i<n; i++){
            vector<int>nodes = graph[i];
            for(int j = 0; j < nodes.size(); j++){
                adj[i].push_back(nodes[j]);
            }
        }
        vector<int>ans;
        vector<bool>visited(n,false);
        dfs(0,ans,visited,adj);

        return result;

    }
};