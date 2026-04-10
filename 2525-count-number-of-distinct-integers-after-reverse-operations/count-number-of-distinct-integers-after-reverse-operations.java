class Solution {
    public int countDistinctIntegers(int[] nums) {
        int n = nums.length;
        int [] ans = new int[2*n];
        int j = n;
         Set<Integer>st = new HashSet<>();
        for(int i = 0; i<n; i++){
            ans[i] = nums[i];
            st.add(ans[i]);
            String s = nums[i] + "";
            String reversed = new StringBuilder(s).reverse().toString();

            int num = Integer.parseInt(reversed);
            ans[j] = num;
            st.add(ans[j]);
            j++;

    



        }


        

        
return st.size();


        
    }
}