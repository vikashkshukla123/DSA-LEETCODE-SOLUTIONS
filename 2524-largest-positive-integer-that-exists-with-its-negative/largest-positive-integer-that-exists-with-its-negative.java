class Solution {
    public int findMaxK(int[] nums) {
        Set<Integer> set = new HashSet<>();
        int ans = -1;
        int n = nums.length;
        for(int i = 0; i<n; i++){
           set.add(nums[i]);
        }

        for(int i = 0; i<n; i++){
            if(nums[i] < 0){
                continue;
            }

            if(set.contains(-nums[i])){
                ans = Math.max(ans,nums[i]);
            }
        }
return ans;

        
    }
}