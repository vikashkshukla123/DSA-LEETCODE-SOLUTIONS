class Solution {
public:
void dfs(int node, vector<bool>&visited,unordered_map<int,vector<int>>&adj){
    visited[node] = true;
    for(auto &ngbr : adj[node]){
        if(!visited[ngbr]){
            dfs(ngbr,visited, adj);
        }
    }
    return;
}
void dfs1(int node, vector<bool>&visited1, unordered_map<int,vector<int>>&adj){
    visited1[node] = true;
    for(auto &ngbr : adj[node]){
        if(!visited1[ngbr]){
            dfs1(ngbr, visited1, adj);

        }
    }
    return;
}
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        int m = invocations.size();
        unordered_map<int,vector<int>>adj;
        for(int i = 0; i < m; i++){
            int u = invocations[i][0];
            int v = invocations[i][1];

            adj[u].push_back(v);
        }

        vector<bool>visited(n,false);
        vector<bool>visited1(n,false);
        dfs(k,visited,adj);


        vector<int>ans;
        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                dfs1(i,visited1, adj);
            }
        }

        bool breaked = false;
        unordered_set<int>st;
        for(int i = 0; i < n; i++){
            if(visited[i] == true && visited1[i] == true){
                breaked = true;
                break;

            }else if(visited[i] == true && visited1[i] == false){
                st.insert(i);
                
            }
        }

        if(breaked){
            for(int i = 0; i < n; i++){
                ans.push_back(i);
            }

        }else{
            for(int i = 0; i < n; i++){
                if(st.find(i) == st.end()){
                    ans.push_back(i);
                }

            }
        }

        




        
return ans;




    }
};