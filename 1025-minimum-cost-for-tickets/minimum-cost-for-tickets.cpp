class Solution {
public:
int solve(int idx,vector<int>&days, vector<int>&costs,vector<int>&dp){
    int n = days.size();
    if(idx >= n) return 0;
    if(dp[idx] != -1) return dp[idx];

    int case1 = costs[0] + solve(idx + 1,days,costs,dp);
    int after7days = upper_bound(begin(days),end(days),days[idx] + 6) - begin(days);
    int case2 = costs[1] + solve(after7days,days,costs,dp);
   
    int after30days = upper_bound(begin(days),end(days),days[idx] + 29) - begin(days);

    int case3 = costs[2] + solve(after30days, days, costs,dp); 
    return dp[idx] = min({case1,case2,case3});
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(367,-1);
        return solve(0,days,costs,dp);
        
    }
};