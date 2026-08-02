class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n  = nums.size();
        long long ans = 0;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                long long a = (1LL * nums[i] * nums[j]);
                long long b = 1LL * gcd(nums[i],nums[j]);
                long long c = b * b;
                ans = max(ans, a/c);
                
            }
        }

        return ans;
    }
};