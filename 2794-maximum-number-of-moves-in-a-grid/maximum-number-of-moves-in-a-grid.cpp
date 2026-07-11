class Solution {
public:
int solve(vector<vector<int>>&grid, int row, int col,vector<vector<int>>&dp){
    int n = grid.size();
    int m = grid[0].size();

    if(row  < 0 || col < 0 || row >= n || col >= m){
        return 0;
    }
    if(dp[row][col] != -1){
        return dp[row][col];
    }

    int case1 = 0;
    int case2 = 0;
    int case3 = 0;
    if(row - 1 >= 0 && col + 1 < m && grid[row-1][col+1] > grid[row][col]){
        case1 = 1 + solve(grid, row-1, col+1,dp);
    }

    if(col + 1 < m && grid[row][col+1] > grid[row][col]){
        case2 = 1 + solve(grid,row,col+1,dp);
    }

    if(row + 1 < n && col + 1 < m && grid[row+1][col+1] > grid[row][col]){
        case3 = 1 + solve(grid, row + 1, col + 1,dp);
    }
return dp[row][col] = max(case1,max(case2,case3));

}
    int maxMoves(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i = 0; i < n; i++){
            int result = solve(grid,i,0,dp);
            ans = max(ans,result);
        }

        return ans;
        
    }
};