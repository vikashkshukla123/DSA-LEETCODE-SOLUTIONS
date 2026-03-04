class Solution {
public:
bool isPossible(int row, int col, vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();

    int cnt1 = 0;
    int cnt2 = 0;
    // row_check
    for(int j = 0; j<m; j++){
        if(mat[row][j] == 1){
            cnt1++;
        }

    }

    if(cnt1 != 1){
        return false;
    }

    // col check
    for(int i = 0; i<n; i++){
        if(mat[i][col] == 1){
            cnt2++;
        }
    }

    if(cnt2 != 1){
        return false;
    }

    return true;
}
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 1){
                    if(isPossible(i,j,mat)){
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};