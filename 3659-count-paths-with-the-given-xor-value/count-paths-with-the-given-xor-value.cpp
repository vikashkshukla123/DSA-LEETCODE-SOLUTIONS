class Solution {
public:
int mod = 1e9 + 7;
int solve(int row, int col, vector<vector<int>>&grid, int k, int curr_xor,vector<vector<vector<int>>>&dp){
    int n = grid.size();
    int m = grid[0].size();

     if(row >= n ||  col >= m){
        return 0;
    }

    if(row == n-1 && col == m-1){
        if((curr_xor ^ grid[row][col]) == k){
            return 1;
        }
        return 0;
    }
    if(dp[row][col][curr_xor] != -1){
        return dp[row][col][curr_xor];
    }


    int solveRight = solve(row + 1, col, grid, k, curr_xor ^ grid[row][col],dp);
    int solveDown = solve(row, col + 1, grid, k, curr_xor ^  grid[row][col],dp);

    return dp[row][col][curr_xor] = (solveRight + solveDown) % mod;

    
}
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m, vector<int>(16,-1)));

        return solve(0,0,grid, k,0,dp);
    }
};