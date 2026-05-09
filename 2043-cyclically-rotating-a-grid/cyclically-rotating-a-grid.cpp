class Solution {
public:
int n, m;
int filling_top;
int filling_bottom;
int filling_left;
int filling_right;
void reverseTheArray(vector<int>&res, int k){
    int n = res.size();
    int k_optimal = k % n;
    reverse(res.begin(), res.begin() + k_optimal);
    reverse(res.begin()+k_optimal, res.end());

    reverse(res.begin(),res.end());
    return;

}
void fillTheArray(vector<int>&res, int&top, int&bottom, int&left, int&right,vector<vector<int>>&ans){
    int idx = 0;
    while(top <= bottom && left <= right  && idx < res.size()){
            for(int i = left ; i <= right; i++){
                ans[top][i] = res[idx];
                idx++;
            }
            top++;
            for(int i = top; i <= bottom; i++){
                ans[i][right] = res[idx];
                idx++;
            }
            right--;

            for(int i = right; i >= left; i--){
                ans[bottom][i] = res[idx];
                idx++;
            }
            bottom--;

            for(int i = bottom; i >= top; i--){
                ans[i][left] = res[idx];
                idx++;
            }
            left++;

            
        }
        return;

}
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        filling_top =  0;
        filling_bottom = n-1;
        filling_left = 0;
        filling_right = m-1;

        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = m-1;
        vector<vector<int>>ans(n,vector<int>(m,0));
        while(top <= bottom && left <= right){
            vector<int>res;
            for(int i = left ; i <= right; i++){
                res.push_back(grid[top][i]);
            }
            top++;
            for(int i = top; i <= bottom; i++){
                res.push_back(grid[i][right]);
            }
            right--;

            for(int i = right; i >= left; i--){
                res.push_back(grid[bottom][i]);
            }
            bottom--;

            for(int i = bottom; i >= top; i--){
                res.push_back(grid[i][left]);
            }
            left++;

            reverseTheArray(res, k);
            fillTheArray(res,filling_top,filling_bottom,filling_left,filling_right,ans);

            
        }

        return ans;
    }
};