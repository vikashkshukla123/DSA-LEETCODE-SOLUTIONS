class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n = score.size();
        int m = score[0].size();
        int cols = k;
        unordered_map<int,int>mp;
        vector<pair<int,int>>p;
        for(int i = 0; i < n; i++){
            mp[score[i][cols]] = i;  
        }
        for(auto it = mp.begin(); it != mp.end(); it++){
            p.push_back({it->first,it->second});
        }
        sort(p.rbegin(),p.rend());

        vector<vector<int>>ans(n,vector<int>(m,0));
        int row_start = 0;
        for(int i = 0; i < p.size(); i++){
            int row = p[i].second;
            for(int col = 0; col < m; col++){
                ans[row_start][col] = score[row][col];
            }
            row_start++;
        }
        return ans;
    }
};