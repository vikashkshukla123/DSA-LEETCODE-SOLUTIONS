class Solution {
    public int furthestDistanceFromOrigin(String moves) {
        int n = moves.length();
        String s = moves;
        // case 1 _ replaced by left
        int pos1 = 0;
        for(int i = 0; i<n; i++){
            if(s.charAt(i) == 'L'){
                pos1 = pos1 - 1;
            }else if(s.charAt(i) == '_'){
                pos1 = pos1 - 1;
            }else{
                pos1 = pos1 + 1;
            }
        }

        // case2 = replaced by R
        int pos2 = 0;
        for(int i = 0; i<n; i++){
            if(s.charAt(i) == 'R'){
                pos2 = pos2 + 1;
            }else if(s.charAt(i) == '_'){
                pos2 = pos2 + 1;
            }else{
                pos2 = pos2 - 1;
            }
        }

        return Math.max(Math.abs(pos1), Math.abs(pos2));
        
    }
}