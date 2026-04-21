class Solution {
    public int[] decode(int[] encoded, int first) {
        int n = encoded.length;
        int []ans = new int[n+1];
        ans[0] = first;
        int karna = first;
        for(int i = 1; i<=n; i++){
            ans[i] = karna ^ encoded[i-1];
            karna = ans[i];

        }
        return ans;
        
    }
}