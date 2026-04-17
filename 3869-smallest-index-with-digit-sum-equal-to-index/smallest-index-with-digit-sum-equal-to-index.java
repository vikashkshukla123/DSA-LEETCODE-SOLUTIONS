class Solution {
    boolean isTrue(int val, int idx){
        int sum = 0;
        while(val != 0){
            int num = val % 10;
            sum += num;
            val = val / 10;
        }

        return (sum == idx);
    }
    public int smallestIndex(int[] nums) {
        int n = nums.length;
        int ans = -1;
        for(int i = 0; i<n; i++){
            boolean check = isTrue(nums[i],i);
            if(check){
                ans = i;
                break;
            }
        }
        return ans;
    }
}