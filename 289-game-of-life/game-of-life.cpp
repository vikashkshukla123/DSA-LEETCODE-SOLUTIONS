class Solution {
public:

bool isSafe(int r, int c,vector<vector<int>>&board){
    int n = board.size();
    int m = board[0].size();


    if(r >= 0 && r  < n && c >= 0 && c < m){
        return true;
    }
    return false;
}
void deadSurvival(int row, int col,vector<vector<int>>&copy, vector<vector<int>>&board){

    int livecell = 0;
    for(int i = -1; i<=1; i++){
        for(int j = -1; j<=1; j++){
            if(i == 0 && j  == 0) continue;
            int newr = row + i;
            int newc = col + j;

            if(isSafe(newr, newc, board) && copy[newr][newc] == 1){
                livecell++;
            }
        }
    }

    if(livecell == 3){
        board[row][col] = 1;
        return;
    }
    
}

void livingSurvival(int row, int col,vector<vector<int>>&copy, vector<vector<int>>&board){
    int live = 0;
    for(int i = -1; i<=1 ;i++){
        for(int j = -1; j<=1; j++){
            if(i == 0 && j == 0) continue;
            int newr = row + i;
            int newc = col + j;

            if(isSafe(newr, newc, board) && copy[newr][newc] == 1){
                live++;
            }
        }
    }

    if(live < 2){
        board[row][col] = 0;
        return;
    }else if(live == 2 || live == 3){
        board[row][col] = 1;
        return;
    }else if(live > 3){
        board[row][col] = 0;
        return;
    }
}
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> copy = board;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(copy[i][j] == 0){
                    deadSurvival(i,j,copy,board);
                }else{
                    livingSurvival(i,j,copy,board);
                }
            }
        }
        return;
    }
};