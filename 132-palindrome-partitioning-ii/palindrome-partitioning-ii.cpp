class Solution {
  public:
  void calculatePallindrome(string &s, vector<vector<bool>>&isPallindrome){
    int n = s.length();
    for(int L = 1; L <= n; L++){
        for(int i = 0; i + L - 1 < n; i++){
            int j = i + L - 1;
            if(i == j){
                isPallindrome[i][j] = true;
            }else if(i + 1 == j){
                isPallindrome[i][j] = (s[i] == s[j]);
            }else{
                isPallindrome[i][j] = (s[i] == s[j] && isPallindrome[i+1][j-1]);
            }
        }
    }
    return;
  }
  int solve(int idx, string &s,vector<vector<bool>>&isPallindrome,vector<int>&dp){
      int n = s.length();
      if(idx == n){
          return 0;
      }
      if(dp[idx] != -1){
        return dp[idx];
      }
      int ans = 1e9;
      for(int j = idx; j < n; j++){
        int len = j - idx + 1;
        if(isPallindrome[idx][idx + len -1]){
            ans = min(ans, 1 + solve(j+1,s,isPallindrome,dp));
        }

      }
      return dp[idx] = ans;
  }
    int minCut(string s) {
         int n = s.length();
         vector<vector<bool>>isPallindrome(n,vector<bool>(n,false));
         calculatePallindrome(s,isPallindrome);
         vector<int>dp(n,-1);
        return solve(0,s,isPallindrome,dp)-1;
        
    }
};