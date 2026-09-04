class Solution {
public:
int mod = 1e9 + 7;
int solve(int idx, int money, int people,int minProfit,vector<int>&group,vector<int>&profit,int totalPeople,vector<vector<vector<int>>>&dp){
    int k = group.size();
    if(idx >= k){
        if(money >= minProfit && people <= totalPeople){
            return 1;
        }else{
            return 0;
        }
    }


    if(dp[idx][money][people] != -1){
        return dp[idx][money][people];
    }


    int case1 = solve(idx + 1, money, people, minProfit, group,profit,totalPeople,dp);
    int case2 = 0;
    if(people + group[idx] <= totalPeople){
        int min_profit = min(money + profit[idx], minProfit);
    case2 = solve(idx + 1, min_profit, people +  group[idx], minProfit, group,profit,totalPeople,dp);
    }


return dp[idx][money][people] = (case1 + case2) % mod;

}
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<vector<int>>>dp(200,vector<vector<int>>(200,vector<int>(200,-1)));
        return solve(0,0,0,minProfit,group,profit,n,dp);
    }
};