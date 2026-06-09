class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = -1e9;
        int mini = 1e9;
        for(int i = 0; i < n ; i++){
            maxi = max(maxi,nums[i]);
            mini = min(mini,nums[i]);
        }

        long long ans = 0;
        for(int i = 0; i < k; i++){
            long long res = maxi - mini;
            ans += res;
        }
        return ans;
    }
};