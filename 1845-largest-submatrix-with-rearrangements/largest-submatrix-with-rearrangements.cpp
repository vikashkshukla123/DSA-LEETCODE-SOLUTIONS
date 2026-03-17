class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = -1e9;
        vector<int>height(m,0);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == 0){
                    height[j] = 0;
                }else{
                   height[j] += 1;
                
                }
            }
            vector<int>temp = height;
            sort(rbegin(temp),rend(temp));
            for(int i = 0; i<m; i++){
                int area = temp[i] * (i + 1);
                ans = max(ans,area);
            }
        }
        return ans;
    }
};