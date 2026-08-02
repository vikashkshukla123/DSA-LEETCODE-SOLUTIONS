class Solution {
public:
int solve(int left, int right, vector<int>&piles,vector<vector<int>>&dp){
    int n = piles.size();
    if(left > right){
        return 0;
    }
    if(left >= n || right < 0){
        return 0;
    }
    if(dp[left][right] != -1){
        return dp[left][right];
    }
    int case1 = piles[left] + min(solve(left + 2, right,piles,dp),solve(left+1,right-1,piles,dp));

    int case2 = piles[right] + min(solve(left + 1, right-1,piles,dp), solve(left, right - 2,piles,dp));

    return dp[left][right] = max(case1,case2);
}
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int totalCoins = 0;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i = 0; i < n; i++){
            totalCoins += piles[i];
        }

        int ans1 = solve(0,n-1,piles,dp);
        int ans2 = totalCoins - ans1;

        return (ans1 > ans2);
        
    }
};