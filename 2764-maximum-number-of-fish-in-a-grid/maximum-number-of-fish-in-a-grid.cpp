class Solution {
public:
vector<vector<int>>dir = {{-1,0},{1,0},{0,1},{0,-1}};
int dfs(int row ,int col, vector<vector<int>>&grid, vector<vector<bool>>&visited){
    int n = grid.size();
    int m = grid[0].size();
    int ans = grid[row][col];
    visited[row][col] = true;

    for(int i = 0; i < 4; i++){
        int newr = row + dir[i][0];
        int newc = col + dir[i][1];

        if(newr >= 0 && newr < n && newc >= 0 && newc < m && !visited[newr][newc] && grid[newr][newc] != 0){
            ans = ans + dfs(newr,newc, grid, visited);
        }
    }

    return ans;
}
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] > 0){
                    int fishCnt = dfs(i,j,grid,visited);
                    ans = max(ans, fishCnt);

                }
            }
        }
        return ans;
    }
};