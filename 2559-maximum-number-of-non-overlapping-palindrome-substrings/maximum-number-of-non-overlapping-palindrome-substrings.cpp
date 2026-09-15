class Solution {
public:
bool isPallindrome(string &s, int i, int j){
    while(i <= j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int solve(string&s, int k, int i, int j,vector<vector<int>>&dp){
    int n = s.length();
    if(i >= n || j >= n){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ans = 0;
    if(isPallindrome(s,i,j)){
        int take = 1 + solve(s, k, j + 1, j + k ,dp);
        int grow = solve(s, k, i, j + 1,dp);
        int nottake = solve(s, k, i + 1, j + 1,dp);
        ans = max(ans, max({take,grow,nottake}));
    }else{
        int grow = solve(s,k,i,j+1,dp);
        int nottake = solve(s,k,i+1,j+1,dp);

        ans = max(ans, max(grow,nottake));
    }

    return dp[i][j] = ans;

}
    int maxPalindromes(string s, int k) {
        int n = s.length();
        if(k == 1){
            return n;
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(s,k,0,k-1,dp);
        
    }
};