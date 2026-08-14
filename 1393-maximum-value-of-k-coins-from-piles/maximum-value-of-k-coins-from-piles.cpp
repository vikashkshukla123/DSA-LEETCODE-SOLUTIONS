class Solution {
public:
int min(int a, int b){
    if(a < b) return a;
    return b;
}
int solve(int idx, vector<vector<int>>&prefixSum, int k,vector<vector<int>>&dp){
    int n = prefixSum.size();
    if(idx >= n) return 0;
    if(dp[idx][k] != -1){
        return dp[idx][k];
    }

    int case1 = 0 + solve(idx + 1, prefixSum,k,dp);
    int case2 = 0;
    for(int j = 0; j < min(k,prefixSum[idx].size()); j++){
        int ans2 = prefixSum[idx][j] + solve(idx + 1, prefixSum, k - (j+1),dp);
        case2 = max(case2,ans2);
    }

    return dp[idx][k] = max(case1,case2);
}
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>>prefixSum;
        vector<vector<int>>dp(1002, vector<int>(2002,-1));
        for(int i = 0; i < n; i++){
            vector<int>prefix1 = piles[i];
            vector<int>calprefix(prefix1.size(),0);
            calprefix[0] = prefix1[0];
            for(int i = 1; i < calprefix.size(); i++){
                calprefix[i] = prefix1[i] + calprefix[i-1];
            }

            prefixSum.push_back(calprefix);
        }

        return solve(0,prefixSum,k,dp);
    }
};