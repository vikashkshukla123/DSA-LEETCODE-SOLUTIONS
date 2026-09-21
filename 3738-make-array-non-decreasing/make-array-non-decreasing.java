class Solution {
    public int maximumPossibleSize(int[] nums) {
         int n = nums.length;
         Deque<Integer>q = new ArrayDeque<>();
         for(int i = n-1; i >= 0; i--){
            while(!q.isEmpty() && q.peekFirst() < nums[i]){
                q.pollFirst();
            }
            q.offerFirst(nums[i]);
         }

        return q.size();
    }
}