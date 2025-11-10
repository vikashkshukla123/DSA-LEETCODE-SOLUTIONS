class Solution {
public:
int f(int i, int j, vector<vector<int>>&grid, int k,vector<vector<vector<int>>>&dp){
    int n = grid.size();
    int m = grid[0].size();
    if(k < 0) return -1e9;
    if(i == n || j == m) return -1e9;
    if(i == n-1 && j == m-1){
        if(min(1,grid[i][j]) <= k){
            return grid[i][j];
        }
        return -1e9;
    }
    if(dp[i][j][k] != -1) return dp[i][j][k];

       int bottom = grid[i][j] + f(i+1,j,grid, k - min(1, grid[i][j]),dp);
    
    
       int right = grid[i][j] + f(i,j+1, grid, k - min(1,grid[i][j]),dp);
    

    return dp[i][j][k] =  max(bottom, right);

}
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));

        int ans = f(0,0,grid, k,dp);
        if(ans < 0) return -1;
        return ans;
    }
};