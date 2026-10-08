class Solution {
    public int scoreOfParentheses(String s) {
        int n = s.length();
        Deque<Integer>q = new ArrayDeque<>();
        int score = 0;
        for(int i = 0; i < n; i++){
            if(s.charAt(i) == '('){
                q.push(score);
                score = 0;
            }else{
                if(s.charAt(i-1) == '('){
                    score = q.peek() + 1;
                }else{
                    score = q.peek() + 2 * score;
                }
                
                 q.pop();
            }

        }
        return score;
    }
}