class Solution {
    public int getMinDistance(int[] nums, int target, int start) {
        int n = nums.length;
        int ans = (int)1e9;
        for(int i = 0; i<n; i++){
            if(nums[i] == target){
                ans = Math.min(ans, Math.abs(i - start));

            }
        }
        return ans;
    }
}