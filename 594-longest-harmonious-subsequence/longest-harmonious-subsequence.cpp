class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        if(n == 1) return 0;
        int left = 0;
        int right = 1;
        sort(nums.begin(),nums.end());
        while(right < n){
            while(nums[right] - nums[left] > 1){
                left++;
            }
            if(nums[right] - nums[left] == 1){
                maxi = max(maxi,right - left + 1);
            }
            right++;
        }
        return maxi;
    }
};