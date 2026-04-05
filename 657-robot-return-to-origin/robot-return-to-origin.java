class Solution {
    public boolean judgeCircle(String moves) {
        int n = moves.length();
        int x = 0;
        int y = 0;
        for(int i = 0; i<n; i++){
            if(moves.charAt(i) == 'U'){
               x += 0;
               y += 1;
            }else if(moves.charAt(i) == 'D'){
                x += 0;
                y -= 1;
            }else if(moves.charAt(i) == 'L'){
                x -= 1;
                y += 0;
            }else{
                x += 1;
                y += 0;
            }
        }

        if(x == 0 && y == 0) return true;
        return false;
    }
}