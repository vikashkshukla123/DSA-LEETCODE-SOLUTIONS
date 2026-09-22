class Solution {
    public int totalHammingDistance(int[] nums) {
        int n = nums.length;
        int ans = 0;
        for(int bit = 0; bit < 32; bit++){
            int cnt1 = 0;
            int cnt0 = 0;
            for(int i = 0; i < n; i++){
                if(((1 << bit) & nums[i]) != 0){
                    cnt1++;
                }else{
                    cnt0++;
                }

            }
            long val = cnt1 * cnt0;
            ans += (int)val;
        }
        return ans;
    }
}