class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.length();
        int num_cols = n / rows;

        vector<vector<char>>mat(rows,vector<char>(num_cols,'$'));
        int k = 0;
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<num_cols; j++){
               mat[i][j] = encodedText[k];
               k++;
            }
        }
        int start_row = 0;
        int start_col = 0;
        string ans = "";
        for(int col = start_row ; col < num_cols; col++){
            start_col = col;
            start_row = 0;
            while(start_row < rows && start_col < num_cols){
               ans += mat[start_row][start_col];
               start_row++;
               start_col++;
            }

        }
        int j = ans.length() - 1;
        while(j >= 0 && ans[j] == ' '){
           ans.pop_back();
           j--;
        }

        return ans;
       
    }
};