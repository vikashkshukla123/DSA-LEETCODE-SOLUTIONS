class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        int sum = 0;
        int f_of_zero = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            f_of_zero += (i * nums[i]);
        }
        
        dp[0] = f_of_zero;
        int ans = dp[0];
        for(int i = 1; i < n ;i++){
            dp[i] = dp[i-1] + sum - (n * (nums[n-i]));
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};