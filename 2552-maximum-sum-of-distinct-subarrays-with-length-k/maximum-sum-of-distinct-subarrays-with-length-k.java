class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        int n = nums.length;
        long ans  = 0;
        int left = 0;
        int right = 0;
        HashMap<Integer,Integer>mp = new HashMap<>();
        long sum = 0;
        while(right < n){
            sum += nums[right];
            mp.put(nums[right], mp.getOrDefault(nums[right], 0) + 1);


            while(left < n && right - left + 1 > k){
                sum -= nums[left];
                mp.put(nums[left], mp.get(nums[left]) - 1);
                if(mp.get(nums[left]) == 0){
                    mp.remove(nums[left]);
                }
                left++;
            }

            if(right - left + 1 == k && mp.size() == k){
                ans = Math.max(ans, sum);
            }
            right++;
        }
        return ans;
        
    }
}