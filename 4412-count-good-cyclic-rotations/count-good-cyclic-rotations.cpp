class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        vector<long long>prefixSum(n,0);
        prefixSum[0] = 1LL * nums[0];
        long long totalSum = nums[0];
        for(int i = 1; i < n; i++){
            prefixSum[i] = 1LL * nums[i] + prefixSum[i-1];
            totalSum += nums[i];
        }
        int ans = 0;
        int minus_idx = -1;
        for(int idx = 0; idx < n; idx++){
            long long leftSum = 0;
            if(idx + n/2 - 1 < n){
            leftSum = prefixSum[idx + n/2 - 1] - (minus_idx >= 0 ? prefixSum[minus_idx] : 0);
            minus_idx++;
            }else{
                leftSum = prefixSum[n-1] - prefixSum[idx - 1] + prefixSum[idx - n/2 - 1];
            }

            long long rightSum = totalSum - leftSum;
            if(leftSum > rightSum){
                ans++;
            }
        }
        

        
return ans;

        
    }
};