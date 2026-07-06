class Solution {
public:
int solve(int row, int col, vector<vector<int>>&grid,vector<vector<int>>&dp){
    int n = grid.size();
    int m = grid[0].size();

    if(row < 0 || col < 0 || row >= n || col >= m){
        return 1e9;
    }

    if(row == n-1){
        return grid[n-1][col];
    }

    if(dp[row][col] != INT_MAX){
        return dp[row][col];
    }


    int case2 = 1e9;
    for(int next_col = 0; next_col < m; next_col++){
        if(next_col == col) continue;

        case2 = min(case2, solve(row + 1, next_col, grid,dp));
    }

    return dp[row][col] = grid[row][col] + case2;
    
}
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        int ans = 1e9;
        for(int i = 0; i < n; i++){
            int result = solve(0,i,grid,dp);
            ans = min(ans,result);

        }
        return ans;
    }
};