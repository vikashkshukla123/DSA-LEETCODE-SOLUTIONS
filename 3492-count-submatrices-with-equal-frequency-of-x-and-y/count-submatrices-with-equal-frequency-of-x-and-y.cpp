class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>X(n,vector<int>(m,0));
        vector<vector<int>>Y(n,vector<int>(m,0));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int cntX = 0;
                int upper = 0;
                int left = 0;
                int diagonal = 0;

                if(i-1 >= 0){
                    cntX += X[i-1][j];
                }

                if(j-1 >= 0){
                    cntX += X[i][j-1];
                }

                if(i-1 >= 0 && j-1 >= 0){
                    cntX -= X[i-1][j-1];
                }

                if(grid[i][j] == 'X'){
                    cntX += 1;
                }

                X[i][j] = cntX;


            }
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int cntY = 0;
                int upper = 0;
                int left = 0;
                int diagonal = 0;

                if(i-1 >= 0){
                    cntY += Y[i-1][j];
                }

                if(j-1 >= 0){
                    cntY += Y[i][j-1];
                }

                if(i-1 >= 0 && j-1 >= 0){
                    cntY -= Y[i-1][j-1];
                }

                if(grid[i][j] == 'Y'){
                    Y[i][j] = cntY + 1;
                }else{
                    Y[i][j] = cntY;
                }


            }
        }

        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int cnt_x = X[i][j];
                int cnt_y = Y[i][j];

                if(cnt_x == cnt_y && cnt_x >= 1){
                    ans++;
                }
            }
        }
return ans;

        
    }
};