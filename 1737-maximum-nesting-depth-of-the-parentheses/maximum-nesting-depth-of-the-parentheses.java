class Solution {
    public int maxDepth(String s) {
        int n = s.length();
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(s.charAt(i) == '('){
                cnt++;
            }else if(s.charAt(i) == ')'){
                cnt--;
            }


            ans = Math.max(ans,cnt);
        }        
        return ans;
    }
}