class Solution {
public:
void shift(vector<int>&shifted, vector<vector<int>>&mat, int row, int total_shift){
  int m = mat[0].size();
  if(row % 2 == 0){
    // left shift
    for(int col = 0; col < m; col++){
        int idx = (col - total_shift + m) % m;
        shifted[idx] = mat[row][col];
    }

  }else{
    // right shift;
    for(int col = 0; col < m; col++){
        int idx = (col + total_shift) % m;
        shifted[idx] = mat[row][col];
    }

  }

  return;
}
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        int total_shift = k % m;
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i = 0; i<n; i++){
            vector<int>shifted(m);
            shift(shifted, mat, i,total_shift);
            ans[i] = shifted;

        }

        return (mat == ans);
        
    }
};