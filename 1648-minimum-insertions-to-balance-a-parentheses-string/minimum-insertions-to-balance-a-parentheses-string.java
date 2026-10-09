class Solution {
    public int minInsertions(String s) {
        int n = s.length();
        int cnt = 0;
        int result = 0;
        int i = 0;
        while(i < n){
            if(s.charAt(i) == '('){
                cnt++;
                i++;
            }else{
                if(cnt > 0){
                    cnt--;
                }else{
                    result++;
                }


                if(i+1 < n && s.charAt(i+1) == ')'){
                    i += 2;
                }else{
                    result++;
                    i++;
                }
            }
        }
        if(cnt > 0) result += (cnt * 2);
        
        return result;
    }
}