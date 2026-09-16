class Solution {
public:
int mod = 1e9 + 7;
long long solve(int absent, int consecutive_late,int n,vector<vector<vector<int>>>&dp){
    if(absent > 1 || consecutive_late > 2){
        return 0;
    }
     if(n == 0){
        return 1;
    }
    if(dp[absent][consecutive_late][n] != -1){
        return dp[absent][consecutive_late][n];
    }

    long long case1 = solve(absent, 0, n-1,dp);
    long long case2 = solve(absent + 1, 0, n-1,dp);
    long long case3 = solve(absent, consecutive_late + 1, n-1,dp);
    

    return dp[absent][consecutive_late][n] = (int) ((case1 + case2 + case3) % mod);
}
    int checkRecord(int n) {
        vector<vector<vector<int>>>dp(3,vector<vector<int>>(3,vector<int>(n+1,-1)));

        return solve(0,0,n,dp);
        
    }
};