class Solution {
public:
int solve(int i, int j, vector<int>&values,vector<vector<int>>&dp){
    // base case
    if(i+1 == j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ans = 1e9;
    for(int k = i+1; k<j; k++){
        ans = min(ans, values[i]*values[j]*values[k] + solve(i,k,values,dp) + solve(k,j,values,dp));
    }
    dp[i][j] = ans;
    return dp[i][j];
}
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,n-1,values,dp);
        
    }
};