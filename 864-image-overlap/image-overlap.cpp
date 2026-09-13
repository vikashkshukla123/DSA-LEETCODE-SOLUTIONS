class Solution {
public:
int solve(int row_offset, int col_offset, vector<vector<int>>&img1, vector<vector<int>>&img2){
    int n = img1.size();
    int m = img1[0].size();

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int row_b = i + row_offset;
            int col_b = j + col_offset;

            if(row_b < 0 || col_b < 0 || row_b >= n || col_b >= m){
                continue;
            }
            int val1 = img1[i][j];
            int val2 = img2[row_b][col_b];

            if(val1 == val2 && val1 == 1){
                cnt++;
            }
        }
    }

    return cnt;
}
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int m = img1[0].size();
        int ans = 0;
        for(int row_offset = -n + 1; row_offset < n; row_offset++){
            for(int col_offset = -m + 1; col_offset < m; col_offset++){
                int count = solve(row_offset,col_offset,img1,img2);
                ans = max(ans,count);
            }
        }
        return ans;
    }
};