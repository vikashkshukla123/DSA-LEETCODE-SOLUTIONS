class Solution {
public:

    vector<long long> minimumDistance(
        int src,
        unordered_map<int,vector<vector<int>>>& adj,
        vector<int>& prices,
        int n
    ){

        vector<long long> minDist(n,1e18);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        minDist[src] = 0;

        pq.push({0,src});

        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            long long dist = it.first;
            int node = it.second;

            if(dist > minDist[node]) continue;

            for(vector<int>& neighbour : adj[node]){

                int newNode = neighbour[0];

                long long distance =
                    1LL * neighbour[1] * neighbour[2];

                if(dist + distance < minDist[newNode]){

                    minDist[newNode] =
                        dist + distance;

                    pq.push({
                        minDist[newNode],
                        newNode
                    });
                }
            }
        }

        return minDist;
    }

    vector<long long> minDist(
        int src,
        unordered_map<int,vector<vector<int>>>& adj,
        int n
    ){

        vector<long long> mindist(n,1e18);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        mindist[src] = 0;

        pq.push({0,src});

        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            long long dist = it.first;
            int node = it.second;

            if(dist > mindist[node]) continue;

            for(vector<int>& neighbour : adj[node]){

                int neighbour_node = neighbour[0];

                long long distance = neighbour[1];

                if(dist + distance < mindist[neighbour_node]){

                    mindist[neighbour_node] =
                        dist + distance;

                    pq.push({
                        mindist[neighbour_node],
                        neighbour_node
                    });
                }
            }
        }

        return mindist;
    }

    vector<int> minCost(
        int n,
        vector<int>& prices,
        vector<vector<int>>& roads
    ) {

        int m = roads.size();

        unordered_map<int,vector<vector<int>>> adj;

        for(int i = 0; i < m; i++){

            int u = roads[i][0];
            int v = roads[i][1];
            int normal_cost = roads[i][2];
            int tax = roads[i][3];

            adj[u].push_back({
                v,
                normal_cost,
                tax
            });

            adj[v].push_back({
                u,
                normal_cost,
                tax
            });
        }

        // changed unordered_map -> vector
        vector<vector<long long>> normal_min_dist(n);

        vector<vector<long long>> with_apple(n);

        for(int i = 0; i < n; i++){

            int src = i;

            vector<long long> dist =
                minDist(src,adj,n);

            normal_min_dist[src] = dist;
        }

        for(int i = 0; i < n; i++){

            int src = i;

            vector<long long> dist =
                minimumDistance(
                    src,
                    adj,
                    prices,
                    n
                );

            with_apple[src] = dist;
        }

        vector<int> ans(n,0);

        for(int i = 0; i < n; i++){

            long long shopMin = prices[i];

            for(int anyOtherShop = 0;
                anyOtherShop < n;
                anyOtherShop++){

                if(anyOtherShop == i) continue;

                long long cost1 =
                    normal_min_dist[i][anyOtherShop];

                long long cost2 =
                    prices[anyOtherShop];

                long long cost3 =
                    with_apple[anyOtherShop][i];

                long long totalCost =
                    cost1 + cost2 + cost3;

                shopMin = min(
                    shopMin,
                    totalCost
                );
            }

            ans[i] = shopMin;
        }

        return ans;
    }
};