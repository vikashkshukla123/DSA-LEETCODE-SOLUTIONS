class Solution {

public:
vector<int>delrow = {-1, 0, 1, 0};
vector<int>delcol = {0, 1, 0, -1};

void bfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>>&grid){
    int n = grid.size();
    int m = grid[0].size();

    vis[row][col] = 1;
    queue<pair<int,int>>q;
    q.push({row,col});

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int i = 0; i < 4;  i++){
                int newr = row + delrow[i];
                int newc = col + delcol[i];

                if(newr >= 0 && newr < n && newc >= 0 && newc < m && !vis[newr][newc] && grid[newr][newc] == '1'){
                    vis[newr][newc] = 1;
                    q.push({newr,newc});
                    
                }
            
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    cnt ++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
        
    }
};