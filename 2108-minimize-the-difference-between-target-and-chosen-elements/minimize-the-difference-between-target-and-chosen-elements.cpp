class Solution {
public:
int T;
int min_diff = INT_MAX;
int m;
void solve(int row, int curr_sum, vector<vector<int>>&mat,vector<vector<bool>>&dp){
    int  n = mat.size();
    if(row == n-1){
        if(abs(curr_sum - T) < min_diff){
            min_diff = abs(curr_sum - T);
        }

        return;
    }
    if(row < 0 || row >= n){
        return;
    }
    if(dp[row][curr_sum] != false){
        return;
    }

    dp[row][curr_sum] = true;

    for(int col = 0; col < m ; col++){
        solve(row + 1, curr_sum + mat[row+1][col], mat,dp);
    }

    return;
}
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        T = target;
        int n = mat.size();
        m = mat[0].size();
        vector<vector<bool>>dp(71,vector<bool>(5001,false));
        for(int col = 0; col < m; col++){
            solve(0,mat[0][col], mat,dp);
        }

        return min_diff;
    }
};