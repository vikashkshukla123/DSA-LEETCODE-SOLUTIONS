class Solution {
public:
static bool cmp(vector<int>&a, vector<int>&b){
    return a[2] > b[2];
}
bool isValid(int row, int col, int n, int m){
    if(row >= 0 && row < n && col >= 0 && col < m){
        return true;
    }
    return false;
}
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        sort(sources.begin(),sources.end(),cmp);
        vector<vector<int>>colored(n,vector<int>(m,0));
        vector<pair<int,int>>dir = {{-1,0},{0,1},{1,0},{0,-1}};
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>>q;

        for(vector<int>&v : sources){
            int x = v[0];
            int y = v[1];
            int color = v[2];
            colored[x][y] = color;
            visited[x][y] = true;
            q.push({{x,y},color});
        }

        while(!q.empty()){
            auto it = q.front();
            int x = it.first.first;
            int y = it.first.second;
            int color = it.second;
            q.pop();

            if(colored[x][y] > color) continue;
            for(int i = 0; i<4; i++){
                int x_new = x + dir[i].first;
                int y_new = y + dir[i].second;


                if(isValid(x_new,y_new,n,m)){
                    if(!visited[x_new][y_new]){
                        colored[x_new][y_new]  = color;
                        visited[x_new][y_new] = true;
                        q.push({{x_new,y_new},color});
                    }

                }
            }
        }
        return colored;
        
    }
};