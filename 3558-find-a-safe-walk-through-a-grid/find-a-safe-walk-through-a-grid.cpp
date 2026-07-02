class Solution {
public:
vector<vector<int>>dir = {{-1,0},{1,0},{0,-1},{0,1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int,pair<int,int>>>pq;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        pq.push({health - grid[0][0],{0,0}});
        visited[0][0] = true;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int h = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(h <= 0) return false;

            if(row == n-1 && col == m-1 && h >= 1){
                return true;
            }


            for(int i = 0; i < 4; i++){
                int newr = row + dir[i][0];
                int newc = col + dir[i][1];

                if(newr >= 0 && newr < n && newc >= 0 && newc < m && !visited[newr][newc]){
                    pq.push({h - grid[newr][newc],{newr,newc}});
                    visited[newr][newc] = true;

                }


            }
        }

        return false;

        
    }
};