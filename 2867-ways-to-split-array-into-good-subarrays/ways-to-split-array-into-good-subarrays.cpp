class Solution {
public:
int mod = 1e9 + 7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size();
        vector<long long>onePosition;
        for(int i = 0; i<n; i++){
            if(nums[i] == 1){
                onePosition.push_back(i);
            }
        }
        if(onePosition.size() <= 1){
            return onePosition.size();
        }

        long long ans = 1;
        for(int i = 1; i<onePosition.size(); i++){
            long long diff = onePosition[i] - onePosition[i-1];
            ans = (ans * diff) % mod;
        }

return (int)ans;
        
    }
};