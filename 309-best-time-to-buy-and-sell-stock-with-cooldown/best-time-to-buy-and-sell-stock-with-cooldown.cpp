class Solution {
public:
int solve(int idx, int buy, vector<int>&prices,vector<vector<int>>&dp){
    int n = prices.size();
    if(idx >= n) return 0;
    if(dp[idx][buy] != -1) return dp[idx][buy];
    int ans = 0;
    if(buy){
        int case1 = -prices[idx] + solve(idx + 1, 0, prices,dp);
        int case2 = 0 + solve(idx + 1, 1, prices,dp);


        ans = max(case1,case2);
    }else{

        int case3 = prices[idx] + solve(idx + 2, 1, prices,dp);
        int case4 = 0 + solve(idx + 1, 0, prices,dp);

        ans = max(ans, max(case3,case4));
    }


    return dp[idx][buy] = ans;
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
        
    }
};