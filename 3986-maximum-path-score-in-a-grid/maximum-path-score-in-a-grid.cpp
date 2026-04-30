class Solution {
public:
int n,m;
int solve(int row, int col, vector<vector<int>>&grid, int k,vector<vector<vector<int>>>&dp){
    if(row >= n || col >= m) return -1e9;
    if(k < 0) return -1e9;

    
    if(row == n-1 && col == m-1){
        if(min(1,grid[row][col]) <= k){
            return grid[row][col];
        }
        return -1e9;
    }
    

    if(dp[row][col][k] != -1){
        return dp[row][col][k];
    }


    int case1 = grid[row][col] + solve(row+1,col, grid, k - min(1,grid[row][col]),dp);
    int case2 = grid[row][col] + solve(row,col+1,grid,k - min(1,grid[row][col]),dp);

    return dp[row][col][k] = max(case1,case2);

    

    
}
    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));

        int ans = solve(0,0,grid,k,dp);
        return ans < 0 ? -1 : ans;
        
    }
};