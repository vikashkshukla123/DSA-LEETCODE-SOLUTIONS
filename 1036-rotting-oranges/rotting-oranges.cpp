class Solution {
public:
typedef pair<int,pair<int,int>>p;
vector<vector<int>>dist = {{-1,0},{1,0},{0,-1},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<p>q;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int fresh = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({0,{i,j}});
                    visited[i][j] = true;
                }

                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        int ans = 0;
        while(!q.empty()){
            int k = q.size();
            for(int i = 0; i < k; i++){
            auto it = q.front();
            q.pop();

            int row = it.second.first;
            int col = it.second.second;
            int time = it.first;

            ans = max(ans,time);

            for(int i = 0; i < 4; i++){
                int newr = row + dist[i][0];
                int newc = col + dist[i][1];

                if(newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 && !visited[newr][newc]){
                    q.push({time + 1, {newr,newc}});
                    visited[newr][newc] = 1;
                    fresh--;
                }
            }

            }
        }
        if(fresh > 0){
            return -1;
        }

        return ans;
        
    }
};