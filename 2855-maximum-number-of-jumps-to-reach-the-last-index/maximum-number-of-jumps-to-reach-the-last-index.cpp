class Solution {
public:
int solve(int idx, vector<int>&nums, int target,vector<int>&dp){
    int n = nums.size();
    if(idx >= n-1){
        return 0;
    }
    if(dp[idx] != -2){
        return dp[idx];
    }
    int ans = -1;
    for(int newIdx = idx + 1; newIdx < n; newIdx++){
        if((nums[newIdx] - nums[idx] <= target) && (nums[newIdx] - nums[idx] >= -1*target)){
            int nayaAnswer = solve(newIdx, nums,target,dp);
            if(nayaAnswer != -1){
                ans = max(ans,1 + nayaAnswer);
            }

        }
    }
return dp[idx] = ans;

}
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp(n,-2);
        return solve(0,nums,target,dp);
        
    }
};