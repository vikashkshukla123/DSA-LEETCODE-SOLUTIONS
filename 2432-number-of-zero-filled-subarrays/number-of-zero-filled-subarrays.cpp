class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        long long continuous_zero = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                continuous_zero++;
                ans += continuous_zero;
            }
            else continuous_zero = 0;
        }
        return ans;
        
    }
};
