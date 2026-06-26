class Solution {
public:
    int maxDistance(string moves) {
        int n = moves.length();
        int x = 0;
        int y = 0;
        int under_scores = 0;
        for(int i = 0; i < n; i++){
            if(moves[i] == '_'){
                under_scores++;
                continue;
            }
            if(moves[i] == 'L'){
                x -= 1;
            }else if(moves[i] == 'R'){
                x += 1;
            }else if(moves[i] == 'U'){
                y -= 1;
            }else{
                y += 1;
            }

        }

        return abs(x) + abs(y) + under_scores;
        
    }
};