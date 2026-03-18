class Solution {
public:
int solve(int idx, string &s, int n,vector<int>&dp){
    if(idx == n){
        return 1;
    }
    if(idx < n && s[idx] == '0'){
        return 0;
    }

    if(dp[idx] != -1) return dp[idx];
  

    // if only taking ith character
    int only_ith_character = solve(idx+1,s,n,dp);

    // if i and i+1 character we are taking
    int both_character = 0;
    if(idx + 1 < n){
    if(s[idx] == '1' || (s[idx] == '2' && s[idx + 1] <= '6')){
        both_character += solve(idx + 2, s, n,dp);
        
    }
    }

    return dp[idx] = only_ith_character + both_character;
}
    int numDecodings(string s) {
        int n = s.length();
        vector<int>dp(n,-1);
        return solve(0,s,n,dp);
        
    }
};