class Solution {
public:
int n,m;
typedef pair<int,pair<int,int>> p;
vector<vector<int>>distance = {{-1,0},{1,0},{0,-1},{0,1}};
    int minimumTime(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>>minTime(n,vector<int>(m,1e9));
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        minTime[0][0] = 0;
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,{0,0}});

        if(grid[0][1] > 1 && grid[1][0] > 1){
            return -1;
        }

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int time = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == m-1){
                return minTime[n-1][m-1];
            }

            if(visited[row][col] == true){
                continue;
            }

            visited[row][col] = true;

            for(int i = 0; i < 4; i++){
                int newr = row + distance[i][0];
                int newc = col + distance[i][1];

                if(newr < 0 || newc < 0 || newr >= n || newc >= m){
                    continue;
                }

                if(grid[newr][newc] <= time + 1){
                    pq.push({time+1,{newr,newc}});
                    minTime[newr][newc] = time + 1;
                }else if((grid[newr][newc] - time) % 2 == 0){
                    pq.push({grid[newr][newc] + 1, {newr,newc}});
                    minTime[newr][newc] = grid[newr][newc] + 1;
                }else{
                    pq.push({grid[newr][newc],{newr,newc}});
                    minTime[newr][newc] = grid[newr][newc];
                }
            }


            


            
        

            

        }


return minTime[n-1][m-1];
        
        
    }
};