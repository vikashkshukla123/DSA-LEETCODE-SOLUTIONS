class Solution {
public:
int solve(int stones,vector<int>&dp){
    if(stones == 0){
        return false;
    }
    if(dp[stones] != -1){
        return (dp[stones] == 1 ? true : false);

    }

    for(int stone = 1; stone * stone <= stones; stone++){
        if(solve(stones - (stone * stone),dp) == false){
            return dp[stones] =  true;
        }
        
    }

    return dp[stones] = false;

}
    bool winnerSquareGame(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};