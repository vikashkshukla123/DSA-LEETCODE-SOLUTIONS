class Solution {
    public int minOperations(int[] nums, int x) {
        int n = nums.length;
        int totalsum = 0;
        for(int i = 0; i < n; i++){
            totalsum += nums[i];
        }
        if(x > totalsum) return -1;

        int needed = totalsum - x;
        int left = 0;
        int right = 0;
        int maxi = Integer.MIN_VALUE;
        int sum = 0;
        while(right < n){
            sum += nums[right];

            while(left < n && sum > needed){
                sum -= nums[left];
                left++;
            }

            if(sum == needed){
                maxi = Math.max(maxi, right - left + 1);
            }
            right++;
        }

        if(maxi == Integer.MIN_VALUE) return -1;
        return n - maxi;
    }
}