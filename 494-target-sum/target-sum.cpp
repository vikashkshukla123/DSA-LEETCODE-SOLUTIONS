class Solution {
public:
int solve(int idx, vector<int>&nums,long long sum, long long  target){
    int n = nums.size();

    if(idx == n){
        return (sum == target);
        return 0;
    }

    long long with_plus  =  solve(idx + 1, nums,sum + nums[idx], target);
    long long  with_minus =  solve(idx + 1, nums, sum - nums[idx], target);

    return with_plus + with_minus;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(0,nums,0,target);
        
    }
};