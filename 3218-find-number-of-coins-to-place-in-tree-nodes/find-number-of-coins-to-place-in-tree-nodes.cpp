class Solution {
public:
vector<long long>dfs(int node, int parent, unordered_map<int,vector<int>>&adj, vector<int>&cost,vector<long long>&placed){
    priority_queue<int>max_heap;
    priority_queue<int,vector<int>,greater<int>>min_heap;
    max_heap.push(cost[node]);
    min_heap.push(cost[node]);

    int nodes = 1;
    for(auto &ngbr : adj[node]){
        if(ngbr == parent) continue;
        vector<long long>temp = dfs(ngbr,node,adj,cost,placed);
        for(int i = 0; i < temp.size(); i++){
            min_heap.push(temp[i]);
            max_heap.push(temp[i]);
            nodes++;
        }
    }

    long long s1 = min_heap.top();
    min_heap.pop();

    if(nodes == 1){
        placed[node] = 1;
        return {cost[node]};
    }

    long long s2 = min_heap.top();
    min_heap.pop();

    if(nodes == 2){
        placed[node] = 1;
        return {s1,s2};
    }

    long long l1 = max_heap.top();
    max_heap.pop();
    if(nodes == 3){
        placed[node] = max(s1*s2*l1, 0LL);
        return {s1,s2,l1};
    }

    long long l2 = max_heap.top();
    max_heap.pop();
    long long l3 = max_heap.top();
    max_heap.pop();


    placed[node] = max({s1*s2*l1, l1*l2*l3,0LL});
    return {s1,s2,l1,l2,l3};

}
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = edges.size() + 1;
        unordered_map<int,vector<int>>adj;
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<long long>placed(n,0);
        dfs(0,-1,adj,cost,placed);
        return placed;
    }
};