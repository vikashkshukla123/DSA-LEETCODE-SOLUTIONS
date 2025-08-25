class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        map<int,vector<int>>mp;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                mp[i-j].push_back(mat[i][j]);
            }
        }
        for(auto &it : mp){
            sort(it.second.begin(),it.second.end());
        }
        vector<vector<int>>res(n,vector<int>(m,0));
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                res[i][j] = mp[i-j].back();
                mp[i-j].pop_back();
            }
        }
        return res;
    }
    
        
        
};