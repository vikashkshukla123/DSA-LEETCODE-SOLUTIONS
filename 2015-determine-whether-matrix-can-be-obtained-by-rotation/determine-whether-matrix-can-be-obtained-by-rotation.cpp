class Solution {
public:
vector<vector<int>>rotate(vector<vector<int>>&mat){
    int n = mat.size();
    vector<vector<int>>newmatrix(n,vector<int>(n,0));
    
    // transapose
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            newmatrix[i][j] = mat[j][i];
        }
       

    }

    // reverse_each_row;
    for(vector<int>&v : newmatrix){
        reverse(v.begin(),v.end());
    }
    return newmatrix;
}
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for(int i = 0; i<4; i++){
            mat = rotate(mat);

            if(mat == target){
                return true;
            }
        }

        return false;
        
    }
};