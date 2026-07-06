class Solution {
public:
int solve(int row, int col, vector<vector<int>>&matrix,vector<vector<int>>&dp){
    int n = matrix.size();
    int m = matrix[0].size();

    if(row < 0 || col < 0 || row >= n || col >= m){
        return 1e9;
    }

    if(row == n-1){
        return matrix[row][col];
    }

    if(dp[row][col] != INT_MAX) return dp[row][col];

    int case1 = solve(row + 1, col - 1, matrix,dp);
    int case2 = solve(row + 1, col, matrix,dp);
    int case3 = solve(row + 1, col + 1, matrix,dp);

    return dp[row][col] = matrix[row][col] + min(case1, min(case2,case3));
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 1e9;
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        for(int col = 0; col < m; col++){
            int result = solve(0,col,matrix,dp);
            ans = min(ans, result);
        }

        return ans;
    }
};