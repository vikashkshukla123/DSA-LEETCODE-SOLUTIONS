class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int maxi = -1e9;
        for(int i = 0; i<n; i++){
            maxi = max(maxi, nums[i]);
        }
        int curr_len = 0;
        int max_len = 0;
        for(int i  = 0; i<n; i++){
            if(nums[i] == maxi){
                curr_len++;
                max_len = max(max_len, curr_len);
            }
            else{
                curr_len = 0;
            }
        }
        return max_len;
    }
};