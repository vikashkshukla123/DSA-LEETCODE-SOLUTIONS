class Solution {
public:
vector<vector<int>>dist = {{-1,0},{1,0},{0,-1},{0,1}};
long long dfs(int row, int col, vector<vector<int>>&grid, vector<vector<bool>>&visited){
    int n = grid.size();
    int m = grid[0].size();

    if(row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0 || visited[row][col] == true){
        return 0;
    }

    visited[row][col] = true;

    long long sum = grid[row][col];
    


    for(int i = 0; i < 4; i++){
        int newr = row + dist[i][0];
        int newc = col + dist[i][1];

        if(newr >= 0 && newr < n && newc >= 0 && newc < m && !visited[newr][newc]){
            sum = sum +  dfs(newr,newc, grid,visited);
        }

    }

    
return sum;


    
}
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0 && !visited[i][j] ){
                    long long total = dfs(i,j,grid,visited);

                    if(total % k== 0){
                        ans++;

                    }
                }
            }
        }

        return ans;
    }
};