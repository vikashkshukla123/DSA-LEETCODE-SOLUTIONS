class Solution {
public:
bool isPossible(int i, int j, vector<vector<char>>&grid){
    int cnt_black = 0;
    int cnt_white = 0;
    for(int k = i; k<i+2; k++){
        for(int l = j; l < j + 2; l++){
            if(grid[k][l] == 'W'){
                cnt_white++;
            }else{
                cnt_black++;
            }
        }
    }

    if(cnt_black == 2 || cnt_white == 2){
        return false;
    }

    return true;
}
    bool canMakeSquare(vector<vector<char>>& grid) {
        for(int i = 0; i<2; i++){
            for(int j = 0; j<2; j++){
                if(isPossible(i,j,grid)){
                    return true;
                }

               
            }
        }
        return false;
    }
};