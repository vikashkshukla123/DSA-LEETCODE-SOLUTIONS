class Solution {
    int mod = 1e9 + 7;
public:
bool match(string &to_fill, string &current){
    for(int i = 0; i<3; i++){
        if(to_fill[i] == current[i]){
            return false;
        }
    }

    return true;

}
int solve(int idx, int last_cols, vector<string>&possibilities,vector<vector<int>>&dp){
    if(last_cols == 0){
        return 1;
    }

    if(dp[idx][last_cols] != -1){
        return dp[idx][last_cols];
    }

    int ways = 0;
    string current_color = possibilities[idx];

    for(int i = 0; i<possibilities.size(); i++){
        string to_fill = possibilities[i];
        if(match(to_fill,current_color)){
            ways = (ways + solve(i,last_cols - 1, possibilities,dp)) % mod;
            
        }
        


    }

    return dp[idx][last_cols] = ways;
}
    int numOfWays(int n) {
        vector<string>possibilities = {"RYR","YRY","GRY","RYG","YRG","GRG","RGR","YGR","GYR","RGY","YGY","GYG"};

        int result = 0;
        vector<vector<int>>dp(12,vector<int>(n,-1));
        for(int i = 0; i<possibilities.size(); i++){
            result = (result + solve(i,n-1,possibilities,dp))%mod;
        }
        return result;
    }
};