class Solution {
public:
typedef pair<int,int> p;
    int minTime(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<vector<int>>>adj;
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int start = edges[i][2];
            int end = edges[i][3];

            adj[u].push_back({v,start,end});

        }

        vector<int>minTime(n,1e9);
        minTime[0] = 0;
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int time = it.first;


            if(node == n-1){
                return time;
            }
            if(time > minTime[node]) continue;
            for(auto &neighbour : adj[node]){
                int neighbour_node = neighbour[0];
                int start = neighbour[1];
                int end = neighbour[2];


                if(time <= end  && time >= start){
                
                    if(minTime[node] + 1 < minTime[neighbour_node]){
                        minTime[neighbour_node] = 1 + minTime[node];
                        pq.push({minTime[neighbour_node],neighbour_node});
                    }
                }else if(time < start){
                    int newTime = start + 1;
                    if(newTime < minTime[neighbour_node]){
                        minTime[neighbour_node] = newTime;
                        pq.push({minTime[neighbour_node], neighbour_node});
                    }

                }else{
                    continue;
                }

            }


        }
        return -1;
        
    }
};