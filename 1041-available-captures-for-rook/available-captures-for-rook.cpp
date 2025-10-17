class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rook_row = 0;
        int rook_col = 0; 
        for(int i = 0; i<8; i++){
            for(int j = 0; j<8; j++){
                if(board[i][j] == 'R'){
                    rook_row = i;
                    rook_col = j;
                    break;
                }
            }
        }
        // left
        int cnt = 0;
        for(int i = rook_col - 1; i>=0; i--){
            if(board[rook_row][i] == 'p'){
                cnt++;
                break;
            }
            else if(board[rook_row][i] == 'B'){
                break;
            }
        }

        // right
        for(int i = rook_col + 1; i<8; i++){
            if(board[rook_row][i] == 'p'){
                cnt++;
                break;
            }
            else if(board[rook_row][i] == 'B'){
                break;
            }

        }

        // top
        for(int i = rook_row - 1; i >= 0; i--){
            if(board[i][rook_col] == 'p'){
                cnt++;
                break;
            }
            else if(board[i][rook_col] =='B'){
                break;
            }
        }
        // bottom
        for(int i = rook_row + 1; i < 8; i++){
            if(board[i][rook_col] == 'p'){
                cnt++;
                break;
            }
            else if(board[i][rook_col] == 'B'){
                break;
            }
        }
return cnt;
        
    }
};