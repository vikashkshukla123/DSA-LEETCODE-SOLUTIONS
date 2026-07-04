class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>maxi(n,0);
        maxi[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            maxi[i] = max(nums[i],maxi[i+1]);
        }

        int ans = -1e9;
        for(int i = 0; i < n - k; i ++){
            int num1 = nums[i];
            int num2_idx = i + k;
            ans = max(ans, num1 + maxi[num2_idx]);
        }
        return ans;
    }
};