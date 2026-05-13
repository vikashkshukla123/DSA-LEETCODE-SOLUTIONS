class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size();
        int maxi = -1e9;
        for(int i = 0; i < n; i++){
            vector<int>account = accounts[i];
            int ans = 0;
            for(int j = 0; j < account.size(); j++){
                ans += accounts[i][j];

            }
            maxi = max(maxi,ans);
        }
        return maxi;
    }
};