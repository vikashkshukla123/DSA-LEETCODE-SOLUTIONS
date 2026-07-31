class Solution {
public:
int solve(int idx, vector<vector<int>>&jobs, vector<int>&startTime,vector<int>&dp){
    int n = jobs.size();
    if(idx >= n){
        return 0;
    }
    if(dp[idx] != -1){
        return dp[idx];
    }

    int notTake = 0 + solve(idx + 1, jobs, startTime,dp);
    int take = -1e9;

    int next_job_idx = lower_bound(begin(startTime),end(startTime), jobs[idx][1]) - begin(startTime);


    take = jobs[idx][2] + solve(next_job_idx, jobs, startTime,dp);

    return dp[idx] = max(take,notTake);
}
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>>jobs;
        for(int i = 0; i < n; i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        vector<int>dp(n,-1);
        sort(startTime.begin(),startTime.end());
        sort(jobs.begin(),jobs.end());

        return solve(0, jobs, startTime,dp);
    }
};