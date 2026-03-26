class Solution {
    List<Integer>solve(String expression){
        int n = expression.length();
        
        List<Integer>ans = new ArrayList<>();
        for(int i = 0; i<n; i++){
            char ch = expression.charAt(i);
            if(ch == '-' || ch == '+' || ch == '*'){
               List<Integer>left =  solve(expression.substring(0,i));
               List<Integer>right = solve(expression.substring(i+1));


               int x = left.size();
               int y = right.size();

               for(int k = 0; k<x; k++){
                for(int l = 0; l<y; l++){
                    int val1 = left.get(k);
                    int val2 = right.get(l);

                    if(ch == '+'){
                        ans.add(val1 + val2);
                    }else if(ch == '-'){
                        ans.add(val1 - val2);
                    }else ans.add(val1 * val2);
                    

                }
               }

            }
        }
        if(ans.isEmpty()){
            ans.add(Integer.parseInt(expression));
        }

        return ans;
    }
    public List<Integer> diffWaysToCompute(String expression) {
        return solve(expression);
        
    }
}