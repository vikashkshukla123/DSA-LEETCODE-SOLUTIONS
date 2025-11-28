class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        // prefixSum[x] = sum of nums[0..x-1]
        vector<long long> prefixSum(n);
        prefixSum[0] = nums[0];
        for(int i = 1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        

        long long result = LLONG_MIN;

        for(int start = 0; start < k; start ++){
            long long currSum = 0;
            int i = start;
            while(i < n && i + k - 1 < n){
            int j = i + k - 1;

            long long subArraySum = prefixSum[j] - ((i > 0) ? prefixSum[i-1] : 0);
            currSum = max(subArraySum, currSum + subArraySum);

            result = max(result, currSum);
            i += k;

            }
            
        }

        return result;
    }
};