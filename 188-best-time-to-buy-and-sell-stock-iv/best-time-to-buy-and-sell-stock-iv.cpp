class Solution {
public:
int f(int idx, int buy, int cap,vector<int>&prices,vector<vector<vector<int>>>&dp){
    if(idx == prices.size()) return 0;
    if(cap == 0) return 0;

    if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];


    if(buy){
        return dp[idx][buy][cap] = max(-prices[idx] + f(idx + 1, 0, cap,prices,dp), 0 + f(idx + 1, 1, cap,prices,dp));
    }else{
        return dp[idx][buy][cap] = max(prices[idx] + f(idx + 1, 1, cap - 1,prices,dp), 0 + f(idx + 1,0, cap,prices,dp));
    }
}
    int maxProfit(int k, vector<int>& prices) {
         int n = prices.size();
vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));

        return f(0,1, k,prices,dp);
        
        
    }
};