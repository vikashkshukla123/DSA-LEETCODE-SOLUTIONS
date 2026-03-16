class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<int>st;
        auto addSet = [&](int sum){
            st.insert(sum);
            if(st.size()>3){
                st.erase(begin(st));
            }


        };
        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                // 0 side rhombus
                addSet(grid[r][c]);

                for(int side = 1; r - side >= 0 && r + side < n && c - side >= 0 && c + side < m; side++){
                    int sum = 0;
                    for(int k = 0; k <= side-1; k++){
                        sum += grid[r-side+k][c + k];
                        sum += grid[r + k][c + side - k];
                        sum += grid[r + side - k][c - k];
                        sum += grid[r - k][c - side + k];
                    }

                    addSet(sum);
                }
            }
        }
        

        return vector<int>(rbegin(st),rend(st));
    }
};