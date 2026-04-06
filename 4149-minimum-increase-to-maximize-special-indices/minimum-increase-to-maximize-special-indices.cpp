class Solution {
public:
int n;
vector<vector<long long>>dp;
long long max(long long a, long long b){
    if(a < b) return b;
    return a;
}
long long solve(int idx, vector<int>&nums ,int flag){
    if(idx >= n-1) return 0;
    if(dp[idx][flag] != -1) return dp[idx][flag];

    int need = max(0,max(nums[idx-1],nums[idx+1]) + 1 - nums[idx]);

    long long skip = 1e18, notSkip = 1e18;
    if(flag == 1) skip = 0 + solve(idx + 1, nums, 0);
    notSkip = need + solve(idx + 2 , nums, flag);

    return dp[idx][flag] = min(skip, notSkip);
}
    long long minIncrease(vector<int>& nums) {
        n = nums.size();
        long long cost = 0;
        if(n % 2 == 1){
            // odd case
            for(int i = 1; i<=n-2; i+=2){
                long long val = max(nums[i-1],nums[i+1])+1;
                cost += max(0,val - nums[i]);


            }
            return cost;

        }else
            dp.assign(n,vector<long long>(2,-1));
            return solve(1,nums,1);


        


        
    }
};