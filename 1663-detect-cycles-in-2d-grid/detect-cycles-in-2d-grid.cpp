class Solution {
public:
vector<vector<int>>dir = {{-1,0},{0,-1},{1,0},{0,1}};
bool dfs(int row, int col, vector<vector<bool>>&visited, vector<vector<char>>&grid, int prev_row, int prev_col){
    int n = grid.size();
    int m = grid[0].size();

    if(visited[row][col]) return true;
    visited[row][col] = true;

    for(int i = 0; i<4; i++){
        int n_row = row + dir[i][0];
        int n_col = col + dir[i][1];

        if(n_row >= 0 && n_row < n &&  n_col >= 0 && n_col < m  &&  grid[n_row][n_col] == grid[row][col]){
            if(n_row == prev_row && n_col == prev_col){
                continue;
            }
            if(dfs(n_row,n_col, visited, grid, row,col)){
                return true;
            }
        }
        
    }
return false;
    
}
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!visited[i][j] && dfs(i,j,visited,grid, i,j)){
                     return true;
                }
            }
        }
        return false;
    }
};