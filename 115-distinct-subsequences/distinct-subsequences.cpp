class Solution {
public:
int solve(int i, int j, string &s, string &t,vector<vector<int>>&dp){
    int n = s.length();
    int m = t.length();
    if(j >= m){
        return 1;
    }
    if(i >= n && j < m){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int take = 0;
    if(s[i] == t[j]){
        take =  solve(i+1,j+1,s,t,dp);
    }
    int nottake = solve(i+1,j,s,t,dp);

    return dp[i][j] = (take + nottake);
}
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(1001,vector<int>(1001,-1));
        return solve(0,0,s,t,dp);
        
    }
};