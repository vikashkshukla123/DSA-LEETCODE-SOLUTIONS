class Solution {
public:
int ans = 1e9;
    int minScore(int n, vector<vector<int>>& roads) {
        int m = roads.size();
        unordered_map<int,vector<vector<int>>>adj;
        vector<bool>visited(n+1,false);
        for(int i = 0; i < m; i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
 
        }

        int ans = 1e9;
        queue<pair<int,int>>q;
        q.push({1,1e9});
        visited[1] = true;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int node = it.first;
            int minWt = it.second;

            ans = min(ans, minWt);

            for(auto &ngbr : adj[node]){
                int nbr = ngbr[0];
                int wt = ngbr[1];

                if(visited[nbr] == true){
                    ans = min(ans,wt);
                }else{
                    q.push({nbr,wt});
                    visited[nbr] = true;

                }
            }
        }

return ans;
        
    }
};