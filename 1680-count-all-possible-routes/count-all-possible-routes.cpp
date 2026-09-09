class Solution {
public:
int mod = 1e9 + 7;

int solve(int start, int fuel, int finish, vector<int>&locations, vector<vector<int>>&dp){
    int n = locations.size();
    if(fuel < 0){
        return 0;
    }

    if(dp[start][fuel] != -1){
        return dp[start][fuel];
    }
    int ans = 0;
    if(start == finish){
        ans = 1;
    }
    for(int i = 0; i < n; i++){
    if(i == start) continue;
    if(fuel >= abs(locations[start] - locations[i])){
      ans = (ans + solve(i ,fuel - abs(locations[start] - locations[i]),finish,locations,dp)) % mod;

    }
   }
   
return dp[start][fuel] = ans;
}
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>>dp(n+1,vector<int>(201+1,-1));
        return solve(start,fuel,finish,locations,dp);
      
    }
};