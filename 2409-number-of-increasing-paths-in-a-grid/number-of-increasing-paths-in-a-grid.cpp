class Solution {
public:
int mod = 1e9 + 7;
int solve(int i, int j, vector<vector<int>>&grid,vector<vector<int>>&dp){
    int n = grid.size();
    int m = grid[0].size();
    
    if(i < 0 || j < 0 || i >= n || j >= m){
        return 0;
    }
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int case1 = 0;
    int case2 = 0;
    int case3 = 0;
    int case4 = 0;
    int ans = 1 ;
    if(i-1 >= 0 && grid[i-1][j] < grid[i][j]){
        ans = (ans + solve(i-1,j,grid,dp)) % mod;
    }
    if(i+1 < n && grid[i+1][j] < grid[i][j]){
        ans = (ans + solve(i+1,j,grid,dp)) % mod;
    }
    if(j+1 < m && grid[i][j+1] < grid[i][j]){
        ans = (ans + solve(i,j+1,grid,dp)) % mod;
    }
    if(j-1 >= 0 && grid[i][j-1] < grid[i][j]){
        ans = (ans + solve(i,j-1,grid,dp)) % mod;
    }
    
    return dp[i][j] = ans;
}
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>>dp(n+1,vector<int>(m,-1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int ways = solve(i,j,grid,dp);
                ans = (ans + ways) % mod;
            }
        }


        return ans;


        
    }
};