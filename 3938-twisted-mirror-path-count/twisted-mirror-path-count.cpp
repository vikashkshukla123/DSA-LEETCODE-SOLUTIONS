class Solution {
    int mod = 1e9 + 7;
public:
int solve(int i, int j, int prev,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
    if(i == grid.size() || j == grid[0].size()){
        return 0;
    }
    if(i == grid.size() - 1 && j == grid[0].size() - 1){
        return 1;
    }
    if(dp[i][j][prev] != -1){
        return dp[i][j][prev];
    }
    
    int right = 0;
    int down = 0;
    if(grid[i][j] == 1){
        if(prev == 0){
            down = solve(i+1,j,1,grid,dp);
        }else{
            right = solve(i,j+1,0, grid, dp);
        }
    }else{
        right = solve(i,j+1,0,grid,dp);
        down = solve(i+1,j,1,grid,dp);



    }

    return dp[i][j][prev] = (down + right) % mod;
}
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(3,-1)));
        return solve(0,0,0, grid, dp);
        
    }
};