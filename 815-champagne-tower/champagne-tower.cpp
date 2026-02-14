class Solution {
public:

double solve(int i, int j, int volume,vector<vector<double>>&dp){
    if(i < j){
        return 0.0;
    }

    if(i < 0 || j < 0){
        return 0.0;
    }

    if(i == 0 && j == 0){
        return volume;

    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    double left_half = (solve(i-1, j-1, volume,dp) - 1 ) / 2.0;
    double right_half = (solve(i-1, j,volume,dp) - 1) / 2.0;

    if(left_half < 0){
        left_half = 0;
    }

    if(right_half < 0){
        right_half = 0;
    }


    return dp[i][j] = left_half + right_half;
    
}
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>dp(101, vector<double>(101 , -1.0));

        return min(1.0,solve(query_row, query_glass, poured,dp));
        
    }
};