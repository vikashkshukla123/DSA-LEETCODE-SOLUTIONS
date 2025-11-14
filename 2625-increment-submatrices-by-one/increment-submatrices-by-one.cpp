class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {

        vector<vector<int>>ans(n,vector<int>(n,0));
        for(int i = 0; i<queries.size(); i++){
            int i1 = queries[i][0];
            int j1 = queries[i][1];
            int i2 = queries[i][2];
            int j2 = queries[i][3];

            for(int k = i1; k<=i2; k++){
                for(int l = j1; l<=j2; l++){
                    ans[k][l] += 1;
                }
            }


        }
        return ans;
        
    }
};