class Solution {
public:
int solve(int idx, vector<int>&rods, int diff,vector<vector<int>>&dp){

    if(idx >= rods.size()){
        if(diff == 0){
            return 0;;
        }else{
            return -1e9;
        }
    }

    if(dp[idx][diff + 5000] != -1){
        return dp[idx][diff+5000];
    }

    // case1 take idx1 length for l1;
    int case1 = rods[idx] + solve(idx + 1, rods, diff + rods[idx],dp);
    int case2 = rods[idx] + solve(idx + 1, rods, diff - rods[idx],dp);
    int case3 = solve(idx + 1, rods, diff,dp);

    return dp[idx][diff+5000] = max(case1,max(case2,case3));
}
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        vector<vector<int>>dp(n,vector<int>(10003,-1));
        
        return solve(0,rods,0,dp)/2;
        
    }
};