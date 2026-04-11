class Solution {
public:
int mod = 1e9 + 7;
int solve(int row, int col, int sum, vector<vector<int>>&grid, int k,vector<vector<vector<int>>>&dp){
    int n = grid.size();
    int m = grid[0].size();

    if (row >= n || col >= m) return 0;

    sum  = (sum + grid[row][col]) % k; 

    if(row == n-1 && col == m-1){
        if(sum % k == 0){
            return 1;
        }
        return 0;
    }

    if(dp[row][col][sum] != -1){
        return dp[row][col][sum];
    }

    int ans1 = solve(row + 1, col, sum , grid,k,dp)%mod;
    int ans2 = solve(row, col + 1, sum , grid,k,dp)%mod;


    return dp[row][col][sum] = (ans1 + ans2)% mod;


    
}
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));


        return solve(0,0,0,grid,k,dp);
        
    }
};