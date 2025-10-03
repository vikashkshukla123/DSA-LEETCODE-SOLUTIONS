class Solution {
    #define pip pair<int,pair<int,int>>
    bool isValid(int&x, int &y, int &n, int &m){
        return (x >= 0 && x < n and y >= 0 && y < m);
    }
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        if(n < 3 or m < 3){
            return 0;
        }
        priority_queue<pip,vector<pip>,greater<pip>>minheap;
        vector<vector<bool>>visited(n, vector<bool>(m,false));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i==0 or i == n-1 or j ==0 or j == m-1){
                    minheap.push(make_pair(heightMap[i][j], make_pair(i,j)));
                    visited[i][j] = true;
                }
            }
        }
        int level = 0;
        int trapped_water = 0;
        vector<int>dir = {-1,0,1,0,-1};
        while(!minheap.empty()){
            pip curr = minheap.top();
            minheap.pop();
            int height = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            level = max(level, height);


            for(int i = 0; i<4; i++){
                int newx = x + dir[i];
                int newy = y + dir[i+1];
                if(isValid(newx, newy , n, m) && !visited[newx][newy]){
                    visited[newx][newy] = true;
                    minheap.push(make_pair(heightMap[newx][newy],make_pair(newx, newy)));
                    if(heightMap[newx][newy] < level){
                        trapped_water += level - heightMap[newx][newy];
                    }
                }
            }
        }

return trapped_water;
        
    }
};