class Solution {
public:
bool isMagic(vector<vector<int>>&grid, int row, int col){

    //check only number till 1 to 9 and no repetition
    unordered_set<int>st;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            int num = grid[row + i][col + j];

            if(num < 1 || num > 9 || st.count(num)){
                return false;
            }else{
                st.insert(num);
            }
        }
    }


    // row sum same  and column sum same
    int SUM = grid[row][col] + grid[row][col+1] + grid[row][col + 2];
    for(int i = 0; i<3; i++){
        int s1 = grid[row + i][col] + grid[row + i][col + 1] + grid[row + i][col + 2];

        if(s1 != SUM){
            return false;
        }


        int s2 = grid[row][col + i] + grid[row + 1][col + i] + grid[row + 2][col + i];

        if(s2 != SUM){
            return false;
        }
    }


    // checking for diagonal 

    int s3 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];

    if(s3 != SUM){
        return false;
    }


    // cheking for antidiagonal sum

    int s4 = grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];

    if(s4 != SUM){
        return false;
    }



    return true;


}
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        for(int i = 0; i<=n-3; i++){
            for(int j = 0; j<=m-3; j++){
                if(isMagic(grid,i,j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};