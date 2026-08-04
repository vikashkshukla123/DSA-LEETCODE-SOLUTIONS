class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        if(source == target){
            return 0;
        }
        unordered_map<int,vector<int>>stops;
        for(int i = 0; i < n; i++){
            vector<int>vec = routes[i];
            for(int j = 0; j < vec.size(); j++){
                stops[routes[i][j]].push_back(i);
            }
        }


        queue<int>pq;
        vector<bool>visited(n,false);
        vector<int>numStops = stops[source];
        int busCount = 0;
        for(int i = 0; i < numStops.size(); i++){
            pq.push(numStops[i]);
            visited[numStops[i]] = true;
        }

        while(!pq.empty()){
        busCount++;

        int size = pq.size();
        for(int i = 0; i < size; i++){
            int stop = pq.front();
            pq.pop();

            vector<int>buses = routes[stop];

            for(int j = 0; j < buses.size(); j++){
                int bus = buses[j];

                if(bus == target) return busCount;

                vector<int>busStops = stops[bus];

                for(int k = 0; k < busStops.size(); k++){
                    
                    if(visited[busStops[k]] == false){
                        pq.push(busStops[k]);
                        visited[busStops[k]] = true;
                    }
                }


                
            }


           





        }
    }

return -1;

        

    
    }
};