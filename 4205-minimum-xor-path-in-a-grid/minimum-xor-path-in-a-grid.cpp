class Solution {
public:
int XOR = 1e9;
void solve(int row, int col, int curr, vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
    int n = grid.size();
    int m = grid[0].size();

    curr = curr ^ grid[row][col];

    if(dp[row][col][curr]){
        return;
    }else{
        dp[row][col][curr] = 1;
    }

    if(row == n-1 && col == m-1){
        XOR = min(XOR,curr);
        return;
    }
   




    if(row + 1 < n){
        solve(row + 1, col, curr,grid,dp);
    }



    if(col + 1 < m){
        solve(row , col + 1, curr, grid,dp);
    }


}
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int curr = 0;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(1024,0)));

        solve(0,0,curr,grid,dp);

        return XOR; 
        
    }
};