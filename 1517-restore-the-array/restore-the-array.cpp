class Solution {
public:
int mod = 1e9 + 7;
int solve(int idx, string &s, int k,vector<int>&dp){
    int n = s.length();
    if(idx >= n){
        return 1;
    }
    if(s[idx] == '0'){
        return 0;
    }
    if(dp[idx] != -1){
        return dp[idx];
    }
    int ans = 0;
    long long number = 0;
    for(int end = idx; end < n; end++){
        number = 1LL * number * 10 + s[end] - '0';
        if(number >= 1 && number <= k){
            ans = (ans + solve(end+1, s,k,dp)) % mod;
            
        }else{
            break;
        }
    }

    return dp[idx] = ans;
}
    int numberOfArrays(string s, int k) {
        vector<int>dp(s.length() + 1,-1);
        return solve(0,s,k,dp);
    }
};