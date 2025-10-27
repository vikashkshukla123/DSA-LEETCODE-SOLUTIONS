class Solution {
    vector<vector<int>>dir = {{-1,0},{0,1},{1,0},{0,-1}};
public:
bool solve(int row, int col, int idx, vector<vector<char>>&board, string &word){
    int n = board.size();
    int m = board[0].size();
    if(idx == word.length()) return true;

    if(row < 0 || row >= n || col < 0 || col >= m || board[row][col] == '$' || board[row][col] != word[idx]) return false;

    char temp = board[row][col];
    board[row][col] = '$';

    for(int i = 0; i<4; i++){
        int newr = row + dir[i][0];
        int newc = col + dir[i][1];
       if(solve(newr,newc, idx + 1, board, word) == true) return true;
        
    }
board[row][col] = temp;

return false;

}
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == word[0]){
                    if(solve(i,j,0,board,word) == true) return true;
                }
            }
        }
        return false;
    }
};