class Solution {
    public int minimumDistance(int[] nums) {
        int n = nums.length;
        int ans = (int)1e9; 
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                for(int k = 0; k<n; k++){
                    if((i != j && j != k && k != i) && (nums[i] == nums[j])  && (nums[j] == nums[k])  && (nums[k] == nums[i])){
                        ans = Math.min(ans, Math.abs(i-j) + Math.abs(j-k) + Math.abs(k-i));
                    }
                }
            }
        }
        return ans == (int) 1e9 ? -1 : ans;
    }
}