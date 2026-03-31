class Solution {
public:
int solve(int i, int j, int operations, string &s,vector<vector<vector<int>>>&dp){
    if(i > j) return 0;
    if(i == j) return 1;
    if(dp[i][j][operations] != -1) return dp[i][j][operations];

    int maxLength = max(solve(i+1,j,operations,s,dp),solve(i,j-1, operations,s,dp));
    int min_operations = min(abs(s[i] - s[j]), 26 - (abs(s[i] - s[j])));

    
    if(operations >= min_operations)  maxLength = max(maxLength, 2 + solve(i+1,j-1, operations - min_operations,s,dp));
    

    return dp[i][j][operations] = maxLength;
    
}
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.length();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        return solve(0,n-1,k,s,dp);
        
    }
};