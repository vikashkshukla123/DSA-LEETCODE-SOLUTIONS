class Solution {
public:
bool isPossible(int mid, vector<vector<int>>&dp,vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();

    int min_row = 1e9;
    int min_col = 1e9;
    int max_row = -1;
    int max_col = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(dp[i][j] >= mid){
                min_row = min(min_row,i);
                max_row = max(max_row,i);
                min_col = min(min_col,j);
                max_col = max(max_col,j);
            }
        }
    }

    if(min_row != 1e9 && max_row != -1 && (max_row - min_row) >= mid){
        return true;
    }
    if(min_col != 1e9 && max_col != -1 && (max_col - min_col) >= mid){
        return true;
    }
return false;
}
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(mat[i][j]){
                    dp[i][j] = 1 + min({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]});
                }
            }
        }

        int low = 0;
        int high = min(n,m);
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid, dp,mat)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return (ans * ans);
    };
};