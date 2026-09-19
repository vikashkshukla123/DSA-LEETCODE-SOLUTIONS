class Solution {
public:
int globalMax = 0;
int solve(int node,int parent, vector<vector<int>>&adj, string& s){
    int firstMax = 0;
    int secondMax = 0;
    for(auto &ngbr : adj[node]){
        if(ngbr != parent){
            int value = solve(ngbr,node,adj,s);
            if(s[ngbr] == s[node]) continue;

           if(secondMax < value){
            secondMax = value;
           }

           if(firstMax < secondMax){
            swap(firstMax,secondMax);
           }
        }
    }

    int case1 = 1 + firstMax + secondMax;
    int case2 = 1;
    int case3 = 1 + max(firstMax,secondMax);


    globalMax = max({globalMax, case1,case2,case3});
    return max(case2,case3);



}
    int longestPath(vector<int>& parent, string s) {
        int m = parent.size();
        vector<vector<int>>adj(m);
        for(int i = 1; i < m; i++){
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }
        solve(0,-1,adj,s);
        return globalMax;

    }
};