class Solution {
public:
long long solve(int idx, vector<int>&nums,vector<int>&colors,vector<long long>&dp){
    int n = nums.size();
    if(idx >= n) return 0;
    if(dp[idx] != -1){
        return dp[idx];
    }

    long long case1 = 0;
    if(idx < n-1 && colors[idx]  != colors[idx+1]){
        long long ans1 = nums[idx] + solve(idx + 1,nums, colors,dp);
        case1 = max(case1,ans1);
    }else{
        long long ans3 = nums[idx] + solve(idx + 2, nums,colors,dp);
        case1 = max(case1,ans3);
    }


    long long case2 = 0 + solve(idx + 1,nums,colors,dp);
 

return dp[idx] = max(case1,case2);

    
}
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        vector<long long>dp(n+1,-1);
        return solve(0,nums,colors,dp);
        
        
    }
};