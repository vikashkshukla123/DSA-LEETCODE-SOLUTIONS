class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>>precompute(n,vector<int>(m,0));
        for(int i = 0; i<n; i++){
            
            for(int j = 0; j<m; j++){
                int precomputeSum = 0;
                if(i-1 >= 0){
                    precomputeSum += precompute[i-1][j];
                }

                if(j-1 >= 0){
                    precomputeSum += precompute[i][j-1];
                }

                if((i - 1 >= 0) && (j - 1 >= 0)){
                    precomputeSum -= precompute[i-1][j-1];

                }

                precomputeSum += grid[i][j];

                if(precomputeSum <= k){
                    ans++;
                }


                precompute[i][j] = precomputeSum;
            }
            
        }

        return ans;
    }
};