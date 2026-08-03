class Solution {
public:
int solve(int idx,vector<int>&stoneValue,vector<int>&dp){
    int n = stoneValue.size();
    if(idx >= n){
        return 0;
    }
    if(dp[idx] != -1){
        return dp[idx];
    }

    int case1 = stoneValue[idx] + min(solve(idx + 2, stoneValue,dp),min(solve(idx + 3,stoneValue,dp), solve(idx + 4, stoneValue,dp)));
    
    int case2 = INT_MIN;
    if(idx + 1 < n){
        case2 = stoneValue[idx] + stoneValue[idx + 1] + min(solve(idx + 3, stoneValue,dp),min(solve(idx + 4,stoneValue,dp), solve(idx + 5, stoneValue,dp)));

    }

    int case3 = INT_MIN;
    if(idx + 2 < n){
        case3 = stoneValue[idx] + stoneValue[idx+1] + stoneValue[idx+2] + 
        min(solve(idx + 4, stoneValue,dp),min(solve(idx + 5,stoneValue,dp), solve(idx + 6, stoneValue,dp)));
    }

    return dp[idx] =  max(case1,max(case2,case3));




}
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int totalCoins = 0;
        for(int i = 0; i < n; i++){
            totalCoins += stoneValue[i];
        }
        vector<int>dp(n,-1);
        

        int AliceScore = solve(0,stoneValue,dp);
        int BobScore = totalCoins - AliceScore;

        if(AliceScore > BobScore){
            return "Alice";
        }else if(BobScore > AliceScore){
            return "Bob";
        }

        return "Tie";
        
    }
};