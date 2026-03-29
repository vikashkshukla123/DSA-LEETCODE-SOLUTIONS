class Solution {
public:
int ans = INT_MAX;

void solve(int row, int col, int curr,
           vector<vector<int>>& grid,
           vector<vector<vector<int>>>& dp) {

    int n = grid.size();
    int m = grid[0].size();

    if (dp[row][col][curr]) return;
    dp[row][col][curr] = 1;

    // Last cell → include it NOW
    if (row == n - 1 && col == m - 1) {
        ans = min(ans, curr ^ grid[row][col]);
        return;
    }

    if (row + 1 < n)
        solve(row + 1, col, curr ^ grid[row][col],grid,dp);

    if (col + 1 < m)
        solve(row, col + 1, curr ^ grid[row][col],grid,dp);
}

int minCost(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<vector<int>>> dp(n,
        vector<vector<int>>(m, vector<int>(1024, 0)));

    solve(0, 0, 0, grid, dp);

    return ans;
}
};