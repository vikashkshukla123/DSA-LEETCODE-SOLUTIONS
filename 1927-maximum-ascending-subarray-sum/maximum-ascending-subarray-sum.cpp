class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        int n = nums.size();
        int curr_sum = nums[0];
        int max_sum = nums[0];
        int r = 1;

        while(r < n){
            while(r < n && nums[r] > nums[r-1]){
                curr_sum += nums[r];
                r++;
            }
            max_sum = max(max_sum, curr_sum);
            if(r < n){
            curr_sum = nums[r];
            r++;
            }
        }
        return max_sum;
    }
};