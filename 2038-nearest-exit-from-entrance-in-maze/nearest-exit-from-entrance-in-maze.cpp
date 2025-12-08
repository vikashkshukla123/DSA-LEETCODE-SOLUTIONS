class Solution {
public:
    vector<vector<int>> dist = {{-1,0},{1,0},{0,1},{0,-1}};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        
        // mark entrance visited
        maze[entrance[0]][entrance[1]] = '+';

        int level = 0;

        while(!q.empty()) {
            int size = q.size();  // number of nodes in current BFS layer

            while(size--) {
                auto [row, col] = q.front();
                q.pop();

                // Check exit, but skip entrance
                if(!(row == entrance[0] && col == entrance[1])) {
                    if(row == 0 || row == n-1 || col == 0 || col == m-1) {
                        return level;
                    }
                }

                for(int i = 0; i < 4; i++) {
                    int newr = row + dist[i][0];
                    int newc = col + dist[i][1];

                    if(newr >= 0 && newr < n && newc >= 0 && newc < m && maze[newr][newc] == '.') {
                        maze[newr][newc] = '+'; // mark visited immediately
                        q.push({newr, newc});
                    }
                }
            }

            level++; // increment after full layer processed
        }

        return -1;
    }
};
