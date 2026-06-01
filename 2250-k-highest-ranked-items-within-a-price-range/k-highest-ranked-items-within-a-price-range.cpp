class Solution {
public:
vector<vector<int>>distance = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int n = grid.size();
        int m = grid[0].size();

        queue<vector<int>>q;
        vector<vector<int>>minDist(n,vector<int>(m,1e9));
        vector<vector<bool>>seen(n,vector<bool>(m,false));
        q.push({0,start[0], start[1]});
        minDist[start[0]][start[1]] = 0;
        while(!q.empty()){
            vector<int>values = q.front();
            q.pop();

            
            int dist = values[0];
            int row = values[1];
            int col = values[2];

            if(minDist[row][col] < dist){
                continue;
            }

            for(int i = 0; i < 4; i++){
                int newr = row + distance[i][0];
                int newc = col + distance[i][1];

                if(newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] != 0){
                    if(dist + 1 < minDist[newr][newc]){
                        minDist[newr][newc] = 1 + dist;
                        q.push({minDist[newr][newc], newr,newc});
                    }
                }
            }
        }

        vector<vector<int>>finalRes;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(minDist[i][j] != 1e9 && grid[i][j] >= pricing[0] && grid[i][j] <= pricing[1]){
                    finalRes.push_back({minDist[i][j], grid[i][j], i, j});
                }
            }
        }

        auto cmp = [&](vector<int>&a, vector<int>&b){
            int minDist1 = a[0];
            int minDist2 = b[0];

            int price1 = a[1];
            int price2 = b[1];

            int row1 = a[2];
            int row2 = b[2];

            int col1 = a[3];
            int col2 = b[3];

            if(minDist1 != minDist2){
                return minDist1 < minDist2;
            }

            if(price1 != price2){
                return price1 < price2;
            }

            if(row1 != row2){
                return row1 < row2;
            }


            return col1 < col2;
            
        };

        sort(finalRes.begin(),finalRes.end(),cmp);
        vector<vector<int>>ans;
        int idx = 0;
        while((k --)  && (idx < finalRes.size())){
            int row = finalRes[idx][2];
            int col = finalRes[idx][3];
            ans.push_back({row,col});
            idx++;

            
        }

    
return ans;

        


        
    }
};