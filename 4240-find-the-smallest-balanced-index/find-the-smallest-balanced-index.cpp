class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        vector<long long>prefixSum(n+1,0);
        for(int i = 0; i<n; i++){
            prefixSum[i+1] = nums[i] + prefixSum[i];
        }

        vector<__int128>suffixMultiply(n+1,1);
        for(int i = n-1; i >= 0; i--){
            if(suffixMultiply[i+1] > LLONG_MAX / nums[i])
                suffixMultiply[i] = LLONG_MAX;
            else
                suffixMultiply[i] = nums[i] * suffixMultiply[i+1];
         }



        int ans = -1;
        for(int i = 0; i<n; i++){
            long long sum = prefixSum[i];
            long long product = suffixMultiply[i+1];


            if(sum == product){
                ans = i;
                break;
            }
        }
        return ans;
    }
};