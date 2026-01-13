class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            int left_idx = i - k;
            int right_idx = i + k;

            if((left_idx < 0) && (right_idx >= n)){
                ans += nums[i];
            }else if((left_idx < 0) && nums[right_idx] < nums[i]){
                ans += nums[i];

            }else if((right_idx >= n)   && (nums[left_idx] < nums[i])){
                ans += nums[i];
            }else if((left_idx >= 0) && (right_idx < n)){
                if((nums[left_idx] < nums[i]) && (nums[right_idx] < nums[i])){
                    ans+= nums[i];
                }
                
            }
        }
        return ans;
    }
};