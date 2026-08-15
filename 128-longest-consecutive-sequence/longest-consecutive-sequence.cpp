class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        sort(nums.begin(),nums.end());
        int curr_len = 1;
        int max_len = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i-1]){
            if(nums[i] == nums[i-1] + 1){
                curr_len++;
            }else{
                max_len = max(max_len,curr_len);
                curr_len = 1;
            }
        }
        }
        max_len = max(max_len,curr_len);

        return max_len;
        
    }
};