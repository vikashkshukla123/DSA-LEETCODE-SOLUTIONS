class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        vector<vector<int>>vec;
        vec.push_back({1,0});
        for(auto& x : restrictions){
            vec.push_back(x);
        }
        vec.push_back({n,INT_MAX});

        sort(vec.begin(),vec.end());
        int m = vec.size();
        for(int i = 1; i < m; i++){
            int d = vec[i][0] - vec[i-1][0];
            vec[i][1] = min(vec[i][1] , vec[i-1][1] + d);
        }


        for(int i = m-2; i >= 0; i--){
            int d = vec[i+1][0] - vec[i][0];
            vec[i][1] = min(vec[i][1], vec[i+1][1] + d);
        }

        int ans = -1e9;
        for(int i = 0; i < m-1; i++){
            int distance = vec[i+1][0] - vec[i][0];
            ans = max(ans, (vec[i+1][1] + vec[i][1] + distance)/2);
        }
        return ans;
    }
};