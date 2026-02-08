class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixSum(n+1,0);
        prefixSum[0] = nums[0];
        for(int i = 0; i<n; i++){
            prefixSum[i+1] = nums[i] + prefixSum[i];
        }


        int ans = 0;
        for(int i = 1; i<n; i++){
            int val1 = nums[i-1];
            int val2 = prefixSum[n] - prefixSum[i];

            int totalEle = n -  i;
            if(val2/totalEle < val1){
                ans++;

            }
        }
        return ans;
    }
};