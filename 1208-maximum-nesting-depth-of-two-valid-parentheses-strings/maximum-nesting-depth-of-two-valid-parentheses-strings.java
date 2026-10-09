class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int n = seq.length();
        int []ans = new int[n];
        int dept = 0;
        for(int i = 0; i < n; i++){
            if(seq.charAt(i) == '('){
                dept++;
                if(dept % 2 == 1){
                    ans[i] = 1;
                }else{
                    ans[i] = 0;
                }
            }else{
                if(dept % 2 == 1){
                    ans[i] = 1;
                }else{
                    ans[i] = 0;
                }
                dept--;
            }
        }
        return ans;
        
    }
}