class Solution {
public:
long long max(long long a, long long b){
    if(a < b) return b;
    return a;
}
    long long minOperations(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for(int i = 1; i<n; i++){
            if(nums[i] < nums[i-1]){
                long long val = nums[i-1] - nums[i];
                ans += val;
            }
        }
        return ans;
    }
};