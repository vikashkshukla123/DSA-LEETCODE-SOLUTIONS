class Solution {
public:
typedef pair<int,int>P;
typedef vector<int> V;
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        unordered_map<int,vector<P>>adj;
        for(auto & edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int>minTime(n,INT_MAX);
        priority_queue<V, vector<V>,greater<V>>pq;
        pq.push({passingFees[0], 0, 0});
        while(!pq.empty()){
            auto top = pq.top();
            int cost = top[0];
            int time = top[1];
            int node = top[2];
            pq.pop();
            if(time > maxTime){
                continue;
            }
            if(time <= maxTime && node == n-1){
                return cost;
            }
            for(auto & p : adj[node]){
                int adjNode = p.first;
                int timeP = p.second;

                if((time + timeP <= maxTime) && (time + timeP < minTime[adjNode])){
                    minTime[adjNode] = time + timeP;
                    pq.push({cost + passingFees[adjNode], time + timeP, adjNode});
                }
            }



            

 
        }
        return -1;
    }
};