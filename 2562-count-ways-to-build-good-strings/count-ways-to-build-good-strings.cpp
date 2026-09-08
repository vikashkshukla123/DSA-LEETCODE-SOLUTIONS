class Solution {
public:
int mod = 1e9 + 7;
int dp[100001];
int solve(int len, int low, int high, int zero, int one){
    if(len > high){
        return 0;
    }

    if(dp[len] != -1){
        return dp[len];
    }
    bool toadd = false;
    if(len >= low && len <= high){
        toadd = true;
    }

        int solve1 = solve(len + zero,low,high,zero,one) % mod;
        int solve2 = solve(len + one, low,high,zero,one) % mod;
        return dp[len] =  (toadd + solve1 + solve2) % mod;

    


}
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp,-1,sizeof(dp));
        return solve(0,low,high,zero,one);
        
    }
};