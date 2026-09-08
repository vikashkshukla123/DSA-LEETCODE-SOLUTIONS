class Solution {
public:
int solve(vector<int>&nums,int operation, vector<bool>&visited,unordered_map<vector<bool>,int>&dp){
    int n = nums.size();
    if(dp.find(visited) != dp.end()){
        return dp[visited];
    }
    int maxScore = 0;
    for(int i = 0; i <= n-1; i++){
        if(visited[i] == true) continue;
        for(int j = i+1; j < n; j++){
            if(visited[j] == true) continue;
            visited[i] = true;
            visited[j] = true;

            int score1 = operation *  gcd(nums[i],nums[j]);
            int score2 = solve(nums,operation+1,visited,dp);
            visited[i] = false;
            visited[j] = false;
            maxScore = max(maxScore,score1 + score2);

        }
    }
    return dp[visited] = maxScore;
}
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool>visited(n,false);
        unordered_map<vector<bool>,int>dp;
        return solve(nums,1,visited,dp);
        
    }
};