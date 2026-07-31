class Solution {
public:
long long solve(int idx, vector<vector<int>>&rides,vector<int>&startRides, int n,vector<long long>&dp){
    if(idx >= rides.size()) return 0;
    if(dp[idx] != -1){
        return dp[idx];
    }

    long long nottake = solve(idx + 1, rides,startRides,n,dp);
    int next_pick_up = lower_bound(begin(startRides),end(startRides),rides[idx][1]) - begin(startRides);

    long long take = (rides[idx][1] - rides[idx][0] + rides[idx][2]) + solve(next_pick_up, rides, startRides,n,dp);

    return dp[idx] = max(take,nottake);
}
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end());
        vector<int>startRides;
        for(int i = 0; i < rides.size(); i++){
            startRides.push_back(rides[i][0]);
        }
        vector<long long>dp(rides.size(),-1);
        return solve(0,rides,startRides, n,dp);
        
    }
};