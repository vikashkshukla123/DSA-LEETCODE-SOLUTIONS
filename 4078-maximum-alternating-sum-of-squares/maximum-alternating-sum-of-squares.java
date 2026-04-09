class Solution {
    public long maxAlternatingSum(int[] nums) {
        int n = nums.length;
        List<Integer>actual = new ArrayList<>();
        for(int i = 0; i<n; i++){
            actual.add(Math.abs(nums[i]));
        }
        Collections.sort(actual);
        int i = 0;
        int j = n-1;

        long ans = 0;
        
        while(i < j){
            long sqaure1 =  1L * actual.get(j) * actual.get(j);
            long square2 =  1L * actual.get(i) * actual.get(i);

            ans += sqaure1;
            ans -= square2;


            i++;
            j--;
        }

        if(n % 2 == 1){
            ans += 1L * actual.get(j) * actual.get(j);            
        }
        

return ans;

        
    }
}