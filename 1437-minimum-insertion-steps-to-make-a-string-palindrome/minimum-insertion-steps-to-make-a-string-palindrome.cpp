class Solution {
public:
int solve(int first, int last, string &s,vector<vector<int>>&dp){
    int n = s.length();
    if(first > last){
        return 0;
    }
    if(last - first == 0){
        return 1;
    }
    if(dp[first][last] != -1){
        return dp[first][last];
    }
    int ans1 = 0;
    int ans2 = 0;
    if(s[first] == s[last]){
        ans1 = 2 + solve(first + 1,last - 1,s,dp);

    }else{
        int case1 = solve(first + 1,last,s,dp);
        int case2 = solve(first,last - 1,s,dp);

        ans2 = max(case1,case2);
    }
return dp[first][last] = max(ans1,ans2);
}
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int pallindromic = solve(0,n-1,s,dp);
        return (n - pallindromic);
        
    }
};