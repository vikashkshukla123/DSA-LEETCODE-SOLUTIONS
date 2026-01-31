class Solution {
    typedef pair<int,int> P;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i = 0; i<times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v,w});
        }

        vector<int>dist(n+1,INT_MAX);
        dist[k] = 0;
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();


            for(auto &p : adj[node]){
                int neighbour = p.first;
                int distance = p.second;


                if(dist[node] + distance < dist[neighbour]){
                    dist[neighbour] = dist[node] + distance;

                    pq.push({dist[neighbour],neighbour});
                }
            }
        }

         int ans = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};