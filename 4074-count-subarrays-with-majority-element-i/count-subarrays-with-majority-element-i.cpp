class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>prefixSum(n+1,0);
        for(int i = 0; i<n; i++){
            int val = nums[i] == target?1 : -1;
            prefixSum[i+1] = prefixSum[i] + val;
        }

        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                if(prefixSum[j+1] - prefixSum[i] > 0){
                    ans++;
                }
            }
        }
        return ans;
    }
};