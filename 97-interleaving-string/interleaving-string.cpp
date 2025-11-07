class Solution {
public:
bool solve(int i, int j,int k, string&s1, string&s2, string&s3,vector<vector<vector<int>>>&dp){
    int n = s1.length();
    int m = s2.length();

    int l = s3.length();

    if(i == n && j == m && k == l) return true;
    if(k == l) return false;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    bool ans = false;

    if(s1[i] == s3[k]){
        ans = ans || solve(i+1,j,k+1,s1,s2,s3,dp);
    }
    if(s2[j] == s3[k]){
        ans =  ans || solve(i, j+1,k+1,s1,s2,s3,dp);
    }
    return dp[i][j][k] = ans;
}
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        vector<vector<vector<int>>> dp(n1+1, vector<vector<int>>(n2+1, vector<int>(n3+1, -1)));
        return solve(0,0,0, s1, s2, s3,dp);

        
    }
};