class Solution {
public:
    vector<pair<int,int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};

    bool isValid(int i, int j, vector<string>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        return (i >= 0 && i < n && j >= 0 && j < m && matrix[i][j] != '#');
    }

    int minMoves(vector<string>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        if(matrix[0][0] == '#') return -1;

        unordered_map<char, vector<pair<int,int>>> mp;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char ch = matrix[i][j];
                if(ch >= 'A' && ch <= 'Z'){
                    mp[ch].push_back({i,j});
                }
            }
        }

        deque<pair<int,int>> dq;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        dq.push_front({0,0});
        dist[0][0] = 0;

        while(!dq.empty()){
            auto [i,j] = dq.front();
            dq.pop_front();

            int d = dist[i][j];

            if(i == n-1 && j == m-1){
                return d;
            }

            char ch = matrix[i][j];

    
            if(ch >= 'A' && ch <= 'Z' && mp.count(ch)){
                for(auto [x,y] : mp[ch]){
                    if(dist[x][y] > d){
                        dist[x][y] = d;
                        dq.push_front({x,y});
                    }
                }
                mp.erase(ch);
            }

            for(auto [dx, dy] : dir){
                int ni = i + dx;
                int nj = j + dy;

                if(isValid(ni,nj,matrix) && dist[ni][nj] > d + 1){
                    dist[ni][nj] = d + 1;
                    dq.push_back({ni,nj});
                }
            }
        }

        return -1;
    }
};