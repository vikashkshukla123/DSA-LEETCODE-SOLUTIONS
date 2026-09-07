class Solution {
public:
int mod = 1e9 + 7;
int dp[2001];
int solve(int n, vector<int>&prev){
    if(n == 0){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }

    int total = (2 * solve(n-1,prev)) % mod;
    if(prev[n] != 0){
    int duplicates = solve(prev[n] - 1,prev);
    total = (total - duplicates + mod) % mod;
    }

    return dp[n] =  total;
}
    int distinctSubseqII(string s) {
        int n = s.length();
        memset(dp,-1,sizeof(dp));
        vector<int>lastSeen(26,0);
        vector<int>prev(n+1,0);

        for(int i = 1; i <= n; i++){
            int idx = s[i-1] - 'a';
            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }


        return (solve(n,prev) - 1 + mod) % mod;
        
    }
};