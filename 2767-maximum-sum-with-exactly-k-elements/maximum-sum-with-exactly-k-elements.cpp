class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;
        while(k != 0){
            ans += nums[n-1];
            nums[n-1] = nums[n-1] + 1;
            k--;

        }
        return ans;
    }
};