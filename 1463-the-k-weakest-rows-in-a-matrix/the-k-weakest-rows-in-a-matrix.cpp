class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>v;
        int n = mat.size();
        int m = mat[0].size();

        for(int i = 0; i<n; i++){
            int sum = 0;
            for(int j = 0; j<m; j++){
                sum += mat[i][j];
            }

            v.push_back({sum,i});
        }


        sort(v.begin(),v.end());
        vector<int>ans;
        int i = 0;
        while(k != 0){
            ans.push_back(v[i].second);
            i++;
            k--;
        }



return ans;
        
        
    }
};