class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>>cum(n,vector<int>(m,0));
        for(int i = 0; i<n; i++){
            int cum_sum = 0;
            for(int j = 0; j<m; j++){
                cum_sum +=  matrix[i][j];
                cum[i][j] = cum_sum;
            }
        }

        int ans = 0;
        for(int s_c = 0; s_c < m; s_c++){
            for(int j = s_c; j<m; j++){
                int cum_sum = 0;
                unordered_map<int,int>mp;
                mp[0] = 1;
                for(int row = 0; row < n; row++){
                    int curr = cum[row][j] - (s_c > 0 ? cum[row][s_c - 1] : 0);
                    cum_sum += curr;

                    int rem = cum_sum - target;

                    if(mp.find(rem) != mp.end()){
                        ans += mp[rem];
                    }

                    mp[cum_sum]++;
                }
            }
        }
return ans;
        
    }
};