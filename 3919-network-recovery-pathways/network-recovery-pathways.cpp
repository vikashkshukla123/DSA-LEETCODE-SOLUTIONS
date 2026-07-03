class Solution {
public:
typedef pair<long long,int> p;
bool isPossible(int weight,unordered_map<int,vector<vector<int>>>&adj, vector<bool>&online,long long k){
    int n = online.size();
    vector<long long>minDist(n,1e15);

    priority_queue<p,vector<p>,greater<p>>pq;
    pq.push({0,0});
    minDist[0] = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        long long distance = it.first;
        int node = it.second;

        if(distance > k) break;

        if(minDist[node] < distance){
            continue;
        }

        if(node == n-1  && distance <= k){
            return true;
        }

        for(auto &ngbr: adj[node]){
            int neighbour = ngbr[0];
            int w = ngbr[1];
           
            if(w < weight) continue;


            if(online[neighbour] == true){
                if(minDist[node] + w < minDist[neighbour]){
                    minDist[neighbour] = minDist[node] + w;

                    pq.push({minDist[neighbour], neighbour});
                }
            }
        }



        
    }
    return false;


}
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int right = -1e9;
        int left  = 1e9;
        unordered_map<int,vector<vector<int>>>adj;
        int n = edges.size();

        for(int i = 0; i < n; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v,w});
            right = max(right, w);
            left  = min(left,w);
        }
        
        int ans = -1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(isPossible(mid, adj,online,k)){
                ans = mid;

                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return ans;
    }
};