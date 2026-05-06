class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        vector<vector<char>>result(n,vector<char>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                result[i][j] = boxGrid[j][i];
            }
        }

        for(vector<char>&row : result){
            reverse(row.begin(),row.end());
        }

        for(int col = 0; col < m; col++){
            for(int row = n-1 ; row >= 0; row--){
                if(result[row][col] == '.'){
                    int stoneRow = -1;
                    for(int k = row - 1; k >= 0; k--){
                        if(result[k][col] == '*'){
                            break;
                        }else if(result[k][col] == '#'){
                            stoneRow = k;
                            break;
                        }
                    }
                    if(stoneRow != -1){
                        result[row][col] = '#';
                        result[stoneRow][col] = '.';
                    }
                }
            }
        }
        return result;
    }
};