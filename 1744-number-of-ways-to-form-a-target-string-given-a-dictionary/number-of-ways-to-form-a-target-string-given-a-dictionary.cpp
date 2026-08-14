class Solution {
public:
int mod = 1e9 + 7;
long long solve(int i, int j,vector<vector<int>>&freq, vector<string>& words, const string &target,vector<vector<long long>>&dp){
    int n = words.size();
    int m = target.length();
    if(j >= m){
        return 1;
    }

    if(i >= words[0].size()){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    long long nottake = solve(i+1,j,freq,words,target,dp);
    long long taken = 1LL *freq[target[j] - 'a'][i] * solve(i+1,j+1,freq,words,target,dp);

    return dp[i][j] = (taken +  nottake) % mod;
}
    int numWays(vector<string>& words, string target) {
        int n = words.size();
        int m = words[0].length();
        vector<vector<int>>freq(27,vector<int>(m+1,0));
        for(int idx = 0; idx < m; idx++){
            for(int i = 0; i < n; i++){
                char ch = words[i][idx];
                freq[ch - 'a'][idx]++;

            }
        }

        vector<vector<long long>>dp(m+1,vector<long long>(target.size() +1,-1LL));
        return solve(0,0,freq,words,target,dp);
        
    }
};