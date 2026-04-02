class Solution {
public:
int t[501][501][3];
int solve(int i, int j, int k, vector<vector<int>>&coins){
    int n = coins.size();
    int m = coins[0].size();

    if(k < 0) return -1e9;

    if(i == n-1 && j == m-1){
       
        if(coins[i][j] < 0 && k > 0){
            return 0;
        }

        return coins[i][j];
        
    }

    if(i >= n || j >= m) return -1e9;

    if(t[i][j][k] != INT_MIN){
        return t[i][j][k];
    }

    int take = coins[i][j] + max(solve(i+1,j,k,coins),solve(i,j+1,k,coins));

    int skip = -1e9;
    if(coins[i][j] < 0 && k > 0){
        int skipDown = solve(i+1,j,k-1,coins);
        int skipRight = solve(i,j+1,k-1,coins);

        skip = max(skipDown,skipRight);
    }


    return t[i][j][k] =  max(skip,take);
    
}
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        for(int i = 0; i<501; i++){
            for(int j = 0; j<501; j++){
                for(int k = 0; k<3; k++){
                    t[i][j][k] = INT_MIN;
                }
            }
        }
        return solve(0,0,2,coins);
        
    }
};