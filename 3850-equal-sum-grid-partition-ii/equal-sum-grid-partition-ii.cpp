class Solution {
public:
typedef long long ll;
ll total_sum = 0;

bool horizontalCut(vector<vector<int>>&grid){
    int n = grid.size();
    int m = grid[0].size();
    unordered_set<ll>st;
    ll curr_sum = 0;
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<m; j++){
            st.insert(grid[i][j]);
            curr_sum += grid[i][j];

        }

        ll bottom_sum = total_sum - curr_sum;

        ll difference = curr_sum - bottom_sum;

        if(difference == 0) return true;
        if(difference == grid[0][0]) return true;
        if(difference == grid[0][m-1]) return true;
        if(difference == grid[i][0]) return true;
        if(i > 0 && m > 1 && st.count(difference)){
            return true;
        }

        if(i > 0 && m > 1 && difference == grid[i][0]){
            return true;
        }

       


        
    }
    return false;
}

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                total_sum += grid[i][j];
            }
        }


        if(horizontalCut(grid)){
            return true;
        }

        reverse(grid.begin(),grid.end());

        if(horizontalCut(grid)){
            return true;
        }

        // check for the vertical cut

        reverse(grid.begin(),grid.end());

        // for row cut taking the tranpose
        vector<vector<int>>transpose(m,vector<int>(n));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                transpose[j][i] = grid[i][j];
            }
        }


        if(horizontalCut(transpose)){
            return true;
        }

        reverse(transpose.begin(),transpose.end());
        if(horizontalCut(transpose)){
            return true;
        }
        

        return false;
    }
};