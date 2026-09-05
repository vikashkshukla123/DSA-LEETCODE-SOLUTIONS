class Solution {
public:
bool solve(int node, unordered_map<int,vector<int>>&adj,vector<int>&colors){
    queue<int>q;
    q.push(node);
    colors[node] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto &ngbr : adj[node]){
            if(colors[ngbr] == colors[node]){
                return false;
            }

            if(colors[ngbr] == -1){
                if(colors[node] == 1){
                    colors[ngbr] = 0;
                    q.push(ngbr);
                }else{
                    colors[ngbr] = 1;
                    q.push(ngbr);
                }
            }
        }
    }
    return true;
}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int k = dislikes.size();
        unordered_map<int,vector<int>>adj;
        for(int i = 0; i < k; i++){
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>colors(n+1,-1);
        for(int node = 1; node <= n; node++){
            if(colors[node] == -1){
                bool solve1 = solve(node,adj,colors);
                if(!solve1){
                    return false;
                }
            }
            
        }
        

    
        return true;
        
    }
};