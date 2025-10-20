class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = 1e9;
        int left = 0;
        int right = 0;
        int sum = 0;
        while(right < n){
            sum += nums[right];

            while(left < n && sum >= target){
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left ++;
                

            }

            right++;

           
            


        }
        if(ans == 1e9){
            return 0;
        }
        return ans;
        
    }
};