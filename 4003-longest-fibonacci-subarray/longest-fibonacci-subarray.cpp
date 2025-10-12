class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2){
            return nums.size();
        }
        int i = 2;
        int max_len = -1e9;
        int len = 2;
        for(int i = 2; i<n; i++){
            if(nums[i-1] + nums[i-2] == nums[i]){
                len ++;

            }else{
                len = 2;
            }
            max_len = max(max_len, len);
        }
        return max_len;
    }
};