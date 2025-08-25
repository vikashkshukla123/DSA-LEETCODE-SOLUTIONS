class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt = 0, curr_count;
        vector<int>histogram(m);
        for(int i = 0; i<n; i++){
            // update current row with histogram
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 1) histogram[j]+=1;
                else histogram[j] = 0;
            }
            // weight, index, prev_count
            stack<vector<int>>st;
            st.push({-1,-1,0});
            for(int j = 0; j<m; j++){
                while(st.top()[0] >= histogram[j])
                st.pop();

                curr_count = histogram[j] * (j - st.top()[1]) + st.top()[2];
                st.push({histogram[j], j, curr_count});
                cnt += curr_count;
            }

        }
        return cnt;
        
    }
};