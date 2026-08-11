class Solution {
public:
int solve(int name, int idx, int M,vector<int>&piles,vector<vector<vector<int>>>&dp){
    int n = piles.size();
    if(idx >= n) return 0;
    if(dp[name][idx][M] != -1){
        return dp[name][idx][M];
    }
    int stones = 0;
    int result = (name == 1 ? -1 : INT_MAX);
    for(int x = 1; x <= min(n-idx,2*M); x++){
        stones += piles[idx + x - 1];
        if(name == 1){
            result = max(result, stones + solve(0,idx + x, max(M,x),piles,dp));
        }else{
            result = min(result, solve(1, idx + x, max(M,x),piles,dp));
        }
    }
return dp[name][idx][M] = result;
}
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return solve(1,0,1,piles,dp);

        
    }
};