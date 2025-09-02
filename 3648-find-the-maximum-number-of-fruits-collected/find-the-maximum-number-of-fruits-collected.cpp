class Solution {
    #define ll long long

    int dfs(const vector<vector<int>>&fruits, int row, int col, int moves, vector<vector<int>>&mem, const vector<pair<int,int>>&dirs){
        int n = fruits.size();

        if(row == n-1 && col == n-1) return moves == 0 ? 0 : 1e9;

        if(moves == 0 || row == col) return 1e9;

        if(mem[row][col] != -1) return mem[row][col];

        ll max_fruits = -1;
        for(auto [delta_row, delta_col] : dirs){
            int new_row = row + delta_row;
            int new_col = col + delta_col;

            if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < n){
                int val = dfs(fruits,new_row, new_col, moves-1, mem, dirs);
                if(val != 1e9){
                    max_fruits = max(max_fruits, (ll)val);
                }
            }
        }
        return mem[row][col] = (max_fruits < 0 ? 1e9 : max_fruits + fruits[row][col]);
    }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        ll first = 0;
        // step 1 for fruits collected along the diagonal;
        for(int i = 0; i<n; i++){
            first += fruits[i][i];
        }
        // step 2 from top-right corner
        vector<pair<int,int>> down_dirs = {{1,-1},{1,0},{1,1}};
        vector<vector<int>>mem(n,vector<int>(n,-1));
        int second = dfs(fruits,0,n-1,n-1,mem, down_dirs);

        // step 3 from bottom left corner
        vector<pair<int,int>> right_dirs = {{-1,1},{0,1},{1,1}};
        for(auto& row : mem) fill(row.begin(),row.end() ,-1);
        int third = dfs(fruits,n-1,0,n-1,mem, right_dirs);

        return first + second + third;

        // 
    }
};