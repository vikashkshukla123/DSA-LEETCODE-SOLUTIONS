class Solution {
public:
typedef pair<int,int>p;
void dijakstra(int startHouse,vector<vector<int>>&minDist,unordered_map<int,vector<int>>&adj){
    minDist[startHouse][startHouse] = 0;
    priority_queue<p,vector<p>,greater<p>>pq;
    pq.push({0,startHouse});
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        int house = it.second;
        int dist = it.first;

        if(dist > minDist[startHouse][house]){
            continue;
        }

        for(auto &ngbr : adj[house]){
            if(dist + 1 < minDist[startHouse][ngbr]){
                minDist[startHouse][ngbr] = dist + 1;
                pq.push({minDist[startHouse][ngbr], ngbr});
            }
        }
    }

    return;
}
    vector<int> countOfPairs(int n, int x, int y) {
         unordered_map<int,vector<int>>adj;
         for(int i = 1; i <= n-1; i++){
            int u = i;
            int v = i + 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
         }

         adj[x].push_back(y);
         adj[y].push_back(x);

         vector<vector<int>>minDist(n+1,vector<int>(n+1,1e9));
         for(int startHouse = 1; startHouse <= n; startHouse++){
            dijakstra(startHouse, minDist, adj);
         }

         vector<int>ans(n,0);
         int dist = 1;
         int result = 0;
         for(int i = 0; i <  n; i++){
            int result = 0;
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    if(minDist[j+1][k+1] == dist){
                        result++;
                    }
                    
                }
            }
            ans[i] = result;
            dist++;

         }
         
        return ans;
    }
};