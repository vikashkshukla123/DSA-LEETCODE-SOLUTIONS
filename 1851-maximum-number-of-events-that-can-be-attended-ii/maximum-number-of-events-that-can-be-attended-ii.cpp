class Solution {
public:
int solve(int idx, vector<vector<int>>&events,int k,vector<int>&start,vector<vector<int>>&dp){
    int n = events.size();
    if(idx >= n){
        return 0;
    }

    if(k <= 0){
        return 0;
    }
    if(dp[idx][k] != -1){
        return dp[idx][k];
    }

    int case1 = 0 + solve(idx + 1,events, k ,start,dp);
    int case2 = -1e9;
    int next_to_search = events[idx][1];

    int idx_2 = upper_bound(start.begin(),start.end(),next_to_search) - start.begin();
    case2 = events[idx][2] + solve(idx_2 , events,k - 1, start,dp);


    return dp[idx][k] =  max(case1,case2);



    
}
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        vector<int>start;
        int n = events.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        for(int i = 0; i < n; i++){
            start.push_back(events[i][0]);
        }
        return solve(0,events,k,start,dp);
    }
};