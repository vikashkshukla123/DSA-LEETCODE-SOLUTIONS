class Solution {
public:
typedef long long ll;
typedef vector<ll>p;
vector<vector<int>>dist = {{0,1},{1,0},{0,-1},{-1,0}};
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        vector<vector<vector<ll>>>distance(m,vector<vector<ll>>(n,vector<ll>(2,1e18)));
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({1,0,0,1});
        distance[0][0][1] = 1;
        while(!pq.empty()){
            vector<ll>vec = pq.top();
            pq.pop();
            ll cost = vec[0];
            ll row = vec[1];
            ll col = vec[2];
            ll action = vec[3];

            if(distance[row][col][action] < cost){
                continue;
            }

            if(row == m-1 && col == n-1){
                return cost;
            }



            if(action == 1){
                for(int i = 0; i < 2; i++){
                    int newr = row + dist[i][0];
                    int newc = col + dist[i][1];

                    if(newr < m && newc < n){
                        long long newcost = (newr + 1) * (newc + 1);
                        if(cost + newcost < distance[newr][newc][0]){
                            distance[newr][newc][0] = cost + newcost;
                            pq.push({cost + newcost, newr,newc,0});
                        }
                    }
                }

                for(int i = 2; i < 4; i++){
                    int newr = row + dist[i][0];
                    int newc = col + dist[i][1];
                    if(newr >= 0 && newc >= 0){
                        long long newcost = (newr + 1) * (newc + 1);
                        newcost += 1LL * penalty[row][col];

                        if(cost + newcost < distance[newr][newc][0]){
                            distance[newr][newc][0] = cost + newcost;
                            pq.push({cost + newcost, newr, newc, 0});
                        }
                    }
                }

                long long stayCost = cost + (1LL * penalty[row][col]);
                if(stayCost  < distance[row][col][0]){
                    distance[row][col][0] = stayCost;
                    pq.push({stayCost, row, col, 0});
                }
                
            }else{
                 for(int i = 2; i < 4; i++){
                    int newr = row + dist[i][0];
                    int newc = col + dist[i][1];

                    if(newr >= 0 && newc >= 0){
                        long long newcost = (newr + 1) * (newc + 1);
                        if(cost + newcost < distance[newr][newc][1]){
                            distance[newr][newc][1] = cost + newcost;
                            pq.push({cost + newcost, newr,newc,1});
                        }
                    }
                }


                 for(int i = 0; i < 2; i++){
                    int newr = row + dist[i][0];
                    int newc = col + dist[i][1];
                    if(newr < m && newc < n){
                        long long newcost = (newr + 1) * (newc + 1);
                        newcost += 1LL * penalty[row][col];

                        if(cost + newcost < distance[newr][newc][1]){
                            distance[newr][newc][1] = cost + newcost;
                            pq.push({cost + newcost, newr, newc, 1});
                        }
                    }
                }

                long long stayCost = cost + (1LL * penalty[row][col]);
                if(stayCost  < distance[row][col][1]){
                    distance[row][col][1] = stayCost;
                    pq.push({stayCost, row, col, 1});
                }

            }
        }

return min(distance[m-1][n-1][0], distance[m-1][n-1][1]);
        
    }
};