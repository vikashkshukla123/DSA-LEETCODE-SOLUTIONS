class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n = nums.size();
        int single_digit_sum = 0;
        int double_digit_sum = 0;
        for(int i = 0; i<n; i++){
            string s = to_string(nums[i]);
            if(s.length() == 2){
                double_digit_sum += nums[i];
            }else{
                single_digit_sum += nums[i];
            }
        }
        if(single_digit_sum != double_digit_sum){
            return true;
        }
        return false;
    }
};