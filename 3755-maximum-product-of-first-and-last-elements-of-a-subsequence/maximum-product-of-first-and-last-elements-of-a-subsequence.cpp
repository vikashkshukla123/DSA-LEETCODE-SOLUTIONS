class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        vector<long long> maxTill(n), minTill(n);

        maxTill[n-1] = nums[n-1];
        minTill[n-1] = nums[n-1];

        for(int i = n - 2; i >= 0; i--) {
            maxTill[i] = max(maxTill[i + 1], (long long)nums[i]);
            minTill[i] = min(minTill[i + 1], (long long)nums[i]);
        }

        long long ans = LLONG_MIN;

        for(int i = 0; i <= n - m; i++) {
            long long val1 = nums[i];

            int idx = i + m - 1;
            if(idx >= n) continue;

            long long mul = 0;   

            if(val1 > 0) {
                mul = val1 * maxTill[idx];
            } 
            else if(val1 < 0) {
                mul = val1 * minTill[idx];
            } 
            else {
                mul = 0;  
            }

            ans = max(ans, mul);
        }

        if(ans == LLONG_MIN) ans = 0;

        return ans;
    }
};
