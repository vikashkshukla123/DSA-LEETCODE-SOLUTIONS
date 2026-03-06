class Solution {
    int N;
    int mod = 1e9 + 7;

public:

int solve(int idx, vector<long long>&distance,
          unordered_map<int,vector<pair<int,int>>>&adj,
          vector<int>&dp){

    if(idx == N) return 1;

    if(dp[idx] != -1) return dp[idx];

    int ans = 0;

    for(auto &it : adj[idx]){
        int node = it.first;

        if(distance[node] < distance[idx]){
            ans = (ans + solve(node,distance,adj,dp)) % mod;
        }
    }

    return dp[idx] = ans;
}

int countRestrictedPaths(int n, vector<vector<int>>& edges) {

    N = n;

    unordered_map<int,vector<pair<int,int>>> adj;

    for(auto &e : edges){
        adj[e[0]].push_back({e[1],e[2]});
        adj[e[1]].push_back({e[0],e[2]});
    }

    priority_queue<
        pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>
    > pq;

    vector<long long> distance(n+1,1e18);

    distance[n] = 0;
    pq.push({0,n});

    while(!pq.empty()){

        auto top = pq.top();
        pq.pop();

        long long dist = top.first;
        int node = top.second;

        if(dist > distance[node]) continue;

        for(auto &it : adj[node]){

            int neighbour = it.first;
            int w = it.second;

            if(distance[node] + w < distance[neighbour]){

                distance[neighbour] = distance[node] + w;

                pq.push({distance[neighbour], neighbour});
            }
        }
    }

    vector<int> dp(n+1,-1);

    return solve(1,distance,adj,dp);
}
};