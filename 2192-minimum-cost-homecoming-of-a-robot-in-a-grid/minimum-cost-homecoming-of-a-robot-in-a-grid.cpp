class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int rows = rowCosts.size();
        int cols = colCosts.size();

        int row_start = startPos[0];
        int col_start = startPos[1];


        int row_end = homePos[0];
        int col_end = homePos[1];

        if(row_start == row_end && col_start == col_end){
            return 0;
        }

        bool row_dir = true;
        bool col_dir = true;
        
        int ans2 = 0;
        if(row_start == row_end){
            if(col_start > col_end){
                col_dir = false;
            }

            if(col_dir){
                for(int col = col_start + 1; col <= min(cols-1, col_end); col++){
                    ans2 += colCosts[col];
                }
            }else{
                for(int col = col_start - 1; col >= max(0, col_end); col--){
                    ans2 += colCosts[col];
                }
            }


            return ans2;

            
        }
        int ans3 = 0;
        if(col_start == col_end){
            if(row_start > row_end){
                row_dir = false;
            }

            if(row_dir){
                for(int row = row_start + 1; row <= min(rows-1, row_end); row++){
                    ans3 += rowCosts[row];

                }
            }else{
                for(int row = row_start - 1; row >= max(0, row_end); row--){
                    ans3 += rowCosts[row];
                }
            }

            return ans3;
        }


        if(row_start > row_end){
            row_dir = false;
        }

        if(col_start > col_end){
            col_dir = false;
        }

        int ans4 = 0;
        if(row_dir){
            for(int row = row_start + 1; row <= min(rows-1, row_end); row++){
                    ans4 += rowCosts[row];

            }
        }else{
            for(int row = row_start - 1; row >= max(0,row_end); row--){
                ans4 += rowCosts[row];
            }
        }


         if(col_dir){
                for(int col = col_start + 1; col <= min(cols-1, col_end); col++){
                    ans4 += colCosts[col];
                }
            }else{
                for(int col = col_start - 1; col >= max(0, col_end); col--){
                    ans4 += colCosts[col];
                }
        }

        

return ans4;
       

        
    }
};