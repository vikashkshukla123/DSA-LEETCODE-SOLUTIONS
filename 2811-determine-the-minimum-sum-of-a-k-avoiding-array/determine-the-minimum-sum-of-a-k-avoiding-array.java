class Solution {
    int mod = (int)1e9 + 7;
    public int minimumSum(int n, int k) {
        long []ans = new long[n];
        long start = 1;
        Set<Long>st = new HashSet<>();
        for(int i = 0; i<n; i++){
            if(i == 0){
                st.add((long)1);
                ans[i] = 1;
            }else{
                start = ans[i-1] + 1;
                while(true){
                    if(st.contains(k - start)){
                        start++;
                        continue;
                    }else{
                        ans[i] = start;
                        st.add(start);
                        break;
                    }

                }
            }
        }
        long sum = 0;
        for(int i = 0; i<n; i++){
            sum += ans[i];
        }

        return (int)sum % mod;
        
    }
}