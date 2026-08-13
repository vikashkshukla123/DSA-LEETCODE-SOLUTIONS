class Solution {
public:
int solve(int idx, int time, vector<int>&satisfaction,vector<vector<int>>&dp){
    int n = satisfaction.size();
    if(idx >= n) return 0;
    if(dp[idx][time] != -1){
        return dp[idx][time];
    }

    int take = time * satisfaction[idx] + solve(idx + 1, time + 1,satisfaction,dp);
    int nottake = 0 + solve(idx + 1, time, satisfaction,dp);

    return dp[idx][time] = max(take,nottake);
}
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<vector<int>>dp(10002,vector<int>(1002,-1));
        sort(satisfaction.begin(),satisfaction.end());
        return solve(0,1,satisfaction,dp);
    }
};