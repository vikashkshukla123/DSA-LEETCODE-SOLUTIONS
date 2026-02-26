class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int n = nums.size();
        vector<int>orginal = nums;
        sort(nums.begin(),nums.end());

        int original_sum = 0;
        for(int i = 0; i<n; i++){
            original_sum += nums[i];
        }
        vector<int>ans;
        int sum1 = 0;
        int idx = n-1;
        while(true){
            sum1 += nums[idx];

            int remaining_sum = original_sum - sum1;
            if(remaining_sum < sum1){
                break;
            }else{
                ans.push_back(nums[idx]);
                idx--;
            }
           
          




            

        }
        ans.push_back(nums[idx]);
        return ans;
    }
};