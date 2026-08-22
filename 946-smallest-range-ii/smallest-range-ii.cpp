class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int diff = nums[n-1] - nums[0];
        for(int i = 0; i < n; i++){
            if(i == n-1){
                int maxi = nums[n-1] + k;
                int mini = nums[0] + k;
                diff = min(diff, maxi - mini);


            }else{
                int maxi = max(nums[n-1] - k, nums[i] + k);
                int mini = min(nums[0] + k, nums[i+1] - k);

                diff = min(diff, maxi - mini);
            }
        }
        return diff;
    }
};