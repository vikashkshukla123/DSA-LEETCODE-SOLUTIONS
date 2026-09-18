class Solution {
public:
void dfs(int idx, vector<vector<int>>&stones,vector<bool>&visited){
    visited[idx] = true;
    int n = stones.size();
    for(int i = 0; i < n; i++){
        if(visited[i] == true){
            continue;
        }
        if(visited[i] == false && stones[idx][0] == stones[i][0]){
            dfs(i,stones,visited);
        }else if(visited[i] == false && stones[idx][1] == stones[i][1]){
            dfs(i,stones,visited);
        }
    }

    return;
}
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int ans = 0;
        vector<bool>visited(n,false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i,stones,visited);
                ans++;
            }

        }
        return (n - ans);
    }
};